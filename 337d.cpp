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
ll visit[100001];
ll d_down[100001];
ll d_up[100001];
ll m1m2[100001][2];
ll m1m2u[100001][2];
map<ll, ll> mp;
struct ddd
{
    ll a, b;
};

bool comp(ddd a, ddd b)
{
    return a.b > b.b;
}
void dfs(ll u)
{
    if (mp[u])
    {
        d_down[u] = 0;
    }
    visit[u] = 1;
    vector<ddd> vv;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (visit[v])
            continue;
        else
        {

            dfs(v);
                d_down[u] = max(d_down[u], d_down[v]);
            vv.push_back({v,d_down[v]});
        }
    }
    sort(vv.begin(), vv.end(), comp);
    if (vv.size() > 1)
    {
        m1m2[u][0] = vv[0].b;
        m1m2[u][1] = vv[1].b;
        m1m2u[u][0]=vv[0].a;
        m1m2u[u][1]=vv[1].a;
    }
    else
    m1m2[u][0]=-MAX;
    if ((graph[u].size() > 1)||(u==1))
        d_down[u]++;
}
void dfs2(ll u)
{
    visit[u] = 1;
    // cout<<d_up[u]<<" ";
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (visit[v])
            continue;
        else
        {
            if (mp[v])
            {
                d_up[v] = 0;
            }   
            d_up[v] = max(d_up[u] + 1, d_up[v]);
            if(m1m2u[u][0]==v)
            d_up[v]=max(d_up[v],m1m2[u][1]+2);
            else
            d_up[v]=max(d_up[v],m1m2[u][0]+2);
            dfs2(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, d;
    cin >> n >> m >> d;
    ll arr[m];

    for (ll i = 0; i < m; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = 1;
    }
    for(int i = 0; i < 100001; i++)
    {
        d_down[i]=-MAX;
        d_up[i]=-MAX;
    }
    
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i <= n; i++)
    {
        visit[i]=0;
    }
    
    dfs(1);
    for(int i = 0; i <= n; i++)
    {
        visit[i]=0;
    }
    if(mp[1])
    d_up[1]=0;
    dfs2(1);
    // cout<<"\n";
    ll a=0;
    for(int i = 1; i <= n; i++)
    {
        // cout<<i<<" "<<d_up[i]<<" "<<d_down[i]<<"\n";
        if((d_up[i]<=d)&&(d_down[i]<=d))
        a++;
    }
    cout<<a;
    
}