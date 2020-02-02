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
struct node
{
    ll v, w;
};
vector<node> graph[100005];
ll ans[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        node d;
        cin >> u >> v >> w;
        d.w = w;
        d.v = v;
        graph[u].push_back(d);
        d.v = u;
        graph[v].push_back(d);
    }
    ll kk[k];
    for (ll i = 0; i < 100005; i++)
        ans[i] = MAX;

    for (ll i = 0; i < k; i++)
    {
        cin >> kk[i];
        ans[kk[i]] = 0;
    }
    priority_queue<pair<ll, ll>> pq;
    unordered_map<ll, ll> vis;

    for (ll i = 0; i < k; i++)
    {
        if (!vis[kk[i]])
        {
            pq.push(make_pair((ll)0, kk[i]));
            vis[kk[i]] = 1;
            while (!pq.empty())
            {
                ll u = pq.top().second;
                vis[u] = 1;

                pq.pop();
                for (ll j = 0; j < graph[u].size(); j++)
                {
                    ll v = graph[u][j].v;
                    ll w = graph[u][j].w;
                    if (ans[v] > ans[u] + w)
                        ans[v] = ans[u] + w, pq.push(make_pair(-1 * w, v));
                }
            }
        }
    }
    while (q--)
    {
        // cout<<"herr";
        ll x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}