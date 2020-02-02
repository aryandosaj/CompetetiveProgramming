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
vll graph[100001];
bool visit[100001];
vll graph2[100001];
bool visit2[100001];
map<ll, ll> mp;
vll sources;
vll temp;
void dfs(ll u)
{
    visit[u] = 1;

    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visit[graph[u][i]])
            dfs(graph[u][i]);
    }
    sources.push_back(u);
}
void scc(ll u)
{
    visit2[u] = 1;
    temp.push_back(u);
    for (ll i = 0; i < graph2[u].size(); i++)
    {
        if (!visit2[graph2[u][i]])
            scc(graph2[u][i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < 100001; i++)
    {
        visit[i] = 0;
        visit2[i] = 0;
    }

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph2[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++)
    {
        if (!visit[i])
            dfs(i);
    }

    for (ll i = sources.size()-1; i >=0 ; i--)
    {
        
        if (!visit2[sources[i]])
        {
            scc(sources[i]);
            if (temp.size() > 1)
            {
                for (ll j = 0; j < temp.size(); j++)
                {
                    // cout<<temp[j]<<" ";
                    mp[temp[j]] = 1;
                }
            }
            temp.clear();
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << (mp[i]) << " ";
    }
}