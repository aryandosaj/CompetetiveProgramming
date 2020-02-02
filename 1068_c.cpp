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
    vll arr;
    ll i;
};
dt g[101];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    map<ll, ll> v;
    vll row[101];
    vll col[101];

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].arr.push_back(v);
    }
    ll r = 1, c = 1, nn = 0;
    ;
    for (ll i = 1; i <= n; i++)
    {
        g[i].i=c;
        row[i].push_back(r);
        col[i].push_back(c++);
        
        for(ll j = 0; j < g[i].arr.size(); j++)
        {
            row[i].push_back(r);
            col[i].push_back(c++);
            ll rr = g[i].arr[j];
            row[rr].push_back(rr);
            col[rr].push_back(g[i].i++);
        }
        r++;
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << row[i].size() << "\n";

        for (ll j = 0; j < row[i].size(); j++)
        {
            cout << row[i][j] << " " << col[i][j] << "\n";
        }
    }
}