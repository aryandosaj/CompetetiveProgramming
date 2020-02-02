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
string s[51];
struct pt
{
    ll x, y;
};
vector<pt> v[2];
unordered_map<ll, unordered_map<ll, ll>> vis;
ll n, r1, r2, c1, c2;

void dfs(ll x, ll y, ll t)
{
    vis[x][y] = 1;
    pt temp;temp.x=x;temp.y=y;
    v[t].push_back(temp);
    for (ll i = -1; i < 2; i++)
    {
        for (ll j = -1; j < 2; j++)
        {
            if ((i == 0) ^ (j == 0))
            {
                if ((i + x >= n) || (i + x < 0) || (j + y >= n) || (j + y < 0))
                    continue;
                if ((s[x + i][y + j] == '0') && (!vis[x + i][y + j]))
                {
                    dfs(x + i, y + j, t);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--,c1--,r2--,c2--;
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    dfs(r1, c1, 0);
    dfs(r2, c2, 1);
    ll ans = MAX;
    for (ll i = 0; i < v[0].size(); i++)
        for (ll j = 0; j < v[1].size(); j++)
        {
            ans = min(ans, (v[0][i].x - v[1][j].x) * (v[0][i].x - v[1][j].x) + (v[0][i].y - v[1][j].y) * (v[0][i].y - v[1][j].y));
            //cout<<ans<<" "<<v[0][i].x<<" "<<v[0][i].y<<" "<<v[1][j].x<<" "<<v[1][j].y<<"\n";
        }
    cout << ans;
}