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
vll graph[3002];
bool visit[3002];
bool cyc[3002];
vector<ll> st;
vll cycle;
ll flag = 0;
void dfs(ll u, ll p)
{
    visit[u] = 1;
    st.push_back(u);
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v == p)
            continue;
        if (visit[v])
        {
            ll ii = st.size() - 1;
            if (flag == 0)
            {
                while (st[ii] != v)
                {
                    cycle.push_back(st[ii]);
                    cyc[st[ii]] = 1;
                    ii--;
                }
                cycle.push_back(v);
                cyc[v] = 1;
                flag = 1;
            }
        }
        else
            dfs(v, u);
    }
    if (!st.empty())
        st.pop_back();
}
ll dist[3002];
void dfs2(ll u)
{
    cyc[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (cyc[v])
            continue;
        dist[v] = dist[u] + 1;
        dfs2(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        cyc[i + 1] = 0;
        visit[i + 1] = 0;
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    visit[0] = 1;
    dfs(1, 0);
    for (int i = 0; i < cycle.size(); i++)
    {
        dist[cycle[i]] = 0;
        dfs2(cycle[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}