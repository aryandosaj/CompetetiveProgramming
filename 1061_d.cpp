#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    ll l, r;
};
bool comp(dt a, dt b)
{
    return a.l < b.l;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x, y;
    cin >> n >> x >> y;
    dt arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i].l >> arr[i].r;
    sort(arr, arr + n, comp);
    map<ll,ll> s;
    ll cost = x + (arr[0].r - arr[0].l) * y;
    s[(arr[0].r)]++;
    for (ll i = 1; i < n; i++)
    {
        ll r = MAX * (1e8);
        if (!s.empty())
        {

            auto p = s.lower_bound(arr[i].l);
            if (p != s.begin())
            {
                p--;
                r = p->first;
            }
        }
        if (arr[i].l <= r)
        {
            cost += (x + (arr[i].r - arr[i].l) * y);
            s[(arr[i].r)]++;
        }
        else
        {
            if (((arr[i].r - r) * y) < (x + (arr[i].r - arr[i].l) * y))
            {
                cost += (arr[i].r - r) * y;
                s[(r)]--;
                if(s[r]==0)s.erase(r);
                s[(arr[i].r)]++;
            }
            else
            {
                cost += (x + (arr[i].r - arr[i].l) * y);
                s[(arr[i].r)]++;
            }
        }
        // cout << cost << " ";
        cost %= MAX;
    }
    cout << cost;
}