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
vll graph2[100005];
vll graph[100005];
bool vis[100005];
bool vis2[100005];
stack<ll> st;
ll dsu[100005];
ll size[100005];
ll d[100005];
ll find(ll a)
{
    while(dsu[a]!=a)a = dsu[a];
    return a;
}
void uni(ll a, ll b)
{
    a = find(a);b = find(b);
    if(size[a]<size[b])
        dsu[a] = dsu[b];
    else
        dsu[b] = dsu[a];
}

ll arr[100005];
void dfs(ll u)
{
    vis[u]=1;
    st.push(u);
    for (auto v : graph[u])
    {
        if (!vis[v])
            dfs(v);
        else
        {
            vll temp;
            ll da=MAX;
            while (st.top() != v)
            {
                ll x =st.top();
                da = min(da,arr[x]);
                temp.push_back(x);
                st.pop();
            }
            temp.push_back(v);
            da= min(da,arr[v]);
            for(ll i = temp.size()-2;i>=0;i--)
            {
                uni(v,temp[i]);da= min(da,arr[temp[i]]);
            }
            d[find(v)]=da;
        }
    }
    st.pop();
}
void dfs2(ll u)
{
    vis2[u]=1;
    ll uu=find(u);
    for(auto v:graph[u])
    {
        if(!vis[v])
        {
            ll vv=find(v);
            if(vv!=uu)
            {
                graph2[vv].push_back(uu);
                graph2[uu].push_back(vv);
                dfs2(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}