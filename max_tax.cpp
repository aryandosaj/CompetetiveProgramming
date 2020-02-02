#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000021
struct dt
{
    ll i, b;
};
stack<ll> st;
stack<ll> est;
ll b[100005];
vll graph[100005];
vll rgraph[100005];
vll sccgraph[100005];
vll scc[100005];
vll tax[100005];
ll dp[100005][201];
ll pre[100005][201];
unordered_map<ll, ll> visit;
unordered_map<ll, ll> mp;
unordered_map<ll, ll> sou;
ll ans = 0;
ll k;

bool comp(dt a, dt b)
{
    return a.b < b.b;
}
void dfs(ll u)
{
    visit[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!visit[v])
            dfs(v);
    }
    st.push(u);
}
void dfsscc(ll u)
{
    visit[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (mp[u] != mp[v])
            sou[mp[v]] = 1, sccgraph[mp[u]].push_back(mp[v]);
        if (!visit[v])
        {
            dfsscc(v);
        }
    }
}
void dfsr(ll u, ll ind)
{
    // cout<<ind <<" : "<<u<<"\n";
    mp[u] = ind;
    scc[ind].push_back(u);
    tax[ind].push_back(b[u]);
    visit[u] = 1;
    for (ll i = 0; i < rgraph[u].size(); i++)
    {
        ll v = rgraph[u][i];
        if (!visit[v])
            dfsr(v, ind);
    }
}
void dpdfs(ll u, ll p)
{
    // cout << u << " ";
    visit[u] = 1;
    ll temp[201];
    ll temp2[201];
    for (ll i = 0; i <= k; i++)
        temp[i] = 0;
    for (ll i = 0; i < sccgraph[u].size(); i++)
    {
        ll v = sccgraph[u][i];

        if (!visit[v])
        {
            dpdfs(v, u);
        }
        for (ll i = 0; i <= k; i++)
        {
            temp[i] = max(temp[i], dp[v][i]);
            temp2[i] = temp[i];
        }
    }
    if (sccgraph[u].size() == 0)
    {
        for (ll i = 0; i <= k; i++)
        {

            dp[u][i] = pre[u][i];
            ans = max(ans, dp[u][i]);
        }
    }
    for (ll i = 1; i <= k; i++)
        temp2[i] = max(temp2[i - 1], temp2[i]);
    // min((ll)tax[u].size() - 1, k)
    if (tax[u].size() == 1)
    {
        for (ll i = 0; i <= k; i++)
        {
            dp[u][i]=max(dp[u][i],pre[u][0]+temp[i]);
        }
    }
    else
    {
        if (sccgraph[u].size() > 0)
            for (ll i = 0; i <= k; i++)
            {
                for (ll j = 0; j <= i; j++)
                {
                    (dp[u][i] = max(dp[u][i], pre[u][j] + temp[i - j]));
                    ans = max(ans, dp[u][j]);
                    // cout<<dp[u][i]<<" ";
                }
                // for(ll j=i+1;j<=k;j++)
                // {
                //     dp[u][j] = max(dp[u][j],pre[u][j]+temp2[j]);
                // }
                // cout<<"\n";
            }
    }
}
void ini()
{
    st = est;
    mp.clear();
    ans = 0;
    visit.clear();
    sou.clear();
    for (ll i = 0; i < 100005; i++)
    {
        b[i] = 0;
        graph[i].clear();
        rgraph[i].clear();
        scc[i].clear();
        tax[i].clear();
        sccgraph[i].clear();
        for (ll j = 0; j <= k; j++)
        {
            dp[i][j] = 0;
            pre[i][j] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m >> k;

        for (ll i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            rgraph[v].push_back(u);
        }
        visit.clear();
        for (ll i = 1; i <= n; i++)
            if (!visit[i])
                dfs(i);
        visit.clear();
        ll ii = 1;
        while (!st.empty())
        {
            ll node = st.top();
            st.pop();
            if (!visit[node])
            {
                // cout<<node<<"-"<<ii<<"\n";
                dfsr(node, ii++);
            }
            sort(tax[ii - 1].begin(), tax[ii - 1].end());
        }

        for (ll i = 1; i < ii; i++)
        {
            for (ll j = 0; j <= k; j++)
            {
                if (j == 0)
                {
                    pre[i][j] = (tax[i][j] * ((ll)tax[i].size() - j));
                    continue;
                }

                if (j < tax[i].size())
                    (pre[i][j] = max(pre[i][j - 1], tax[i][j] * ((ll)tax[i].size() - j)));
                else
                    pre[i][j] = max((ll)0, pre[i][j - 1]);
            }
        }
        visit.clear();
        for (ll i = 1; i <= n; i++)
            if (!visit[i])
                dfsscc(i);
        visit.clear();
        for (ll i = 1; i < ii; i++)
        {
            if ((!visit[i]) && (!sou[i]))
                dpdfs(i, 0);
        }
        cout << ans % MAX << "\n";
    }
}