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
    ll x1, x2, y;
};
bool comp(dt a, dt b)
{
    return a.y < b.y;
}
vector<ll> ver;
vector<dt> hor;
ll n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        ver.push_back(a);
    }

    for (ll i = 0; i < m; i++)
    {
        dt temp;
        cin >> temp.x1 >> temp.x2 >> temp.y;
        hor.push_back(temp);
    }
    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end(), comp);
    ll step = m;
    for (ll j = 0; j <= min(n, step); j++)
    {
        ll start, end;
        if (j == 0)
            start = 1;
        else
            start = ver[j - 1];
        if (j == n)
            end = 1e9;
        else
            end = ver[j];
        ll s = j;
        for (ll i = m - 1; i >= 0; i--)
        {
            if ((hor[i].x1 > start) || (hor[i].x2 < end))
                continue;
            else
                s++;
            if(s>step)
            break;
        }
        step=min(s,step);
    }
    cout<<step;
}