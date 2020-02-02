#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
struct dt
{
    ll id, p;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll arr[n + 2];

    for (ll i = 0; i < n + 2; i++)
    {
        arr[i] = 0;
    }

    for (ll i = 0; i < k; i++)
    {
        ll l, r, p;
        cin >> l >> r >> p;
        p = p / (r - l + 1);
        arr[l] += p;
        arr[r + 1] -= p;
    }

    for (ll i = 1; i < n + 2; i++)
    {
        arr[i] += arr[i - 1];
    }
    ll ans[n + 1];

    for (ll i = 1; i < n + 1; i++)
    {
        cin >> ans[i];
    }
    vll a, b, c;
    ll need[n + 1];
    vector<dt> neg;
    vector<dt> pos;

    for (ll i = 1; i < n + 1; i++)
    {
        dt temp;
        need[i] = ans[i] - arr[i];
        temp.id = i;
        temp.p = need[i];

        if (need[i] < 0)
            neg.push_back(temp);
        else if (need[i] > 0)
            pos.push_back(temp);
    }
    ll t2 = 0;
    for (ll i = 0; i < pos.size(); i++)
    {
        while (pos[i].p > 0)
        {
            while (neg[t2].p == 0)
                t2++;
            a.push_back(pos[i].id);
            b.push_back(neg[t2].id);

            if (pos[i].p >= (-1 * neg[t2].p))
            {
                pos[i].p += neg[t2].p;
                c.push_back(-1 * neg[t2].p);
                neg[t2].p = 0;
                t2++;
            }
            else
            {
                neg[t2].p += pos[i].p;
                c.push_back(pos[i].p);
                pos[i].p = 0;
                if (neg[t2].p == 0)
                    t2++;
            }
            if (t2 == n)
                break;
        }
    }
    cout<<a.size()<<"\n";
    for (ll i = 0; i < a.size(); i++)
    {
        cout << b[i] << " " << a[i] << " " << c[i] << "\n";
    }
}