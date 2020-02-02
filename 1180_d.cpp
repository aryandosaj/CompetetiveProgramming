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
vector<pair<ll, ll>> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        ll x = i, y = 1;
        ll xx = n - i + 1, yy = m;
        if (x > xx)
            break;
        else if (x == xx)
        {
            while(y<yy){ans.push_back({x,y++});ans.push_back({x,yy--});}if(y==yy)ans.push_back({x,y});
        }
        else
        {
            for (ll j = 0; j < m; j++)
            {
                ans.push_back({x, y + j});
                ans.push_back({xx, yy - j});
            }
        }
    }
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << "\n";
    }
}