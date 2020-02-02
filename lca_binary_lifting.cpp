#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vll graph[100005];
ll l;
unordered_map<ll,ll>vis;
unordered_map<ll,ll>tin;
unordered_map<ll,ll>tout;
ll tim;
ll up[100005][60];
void dfs(ll u,ll p)
{
    tim++;
    tin[u]=tim;
    vis[u]=1;
    up[u][0]=p;
    for(ll i=1;i<=l;i++)
        up[u][i] = up[up[u][i-1]][i-1];        
    vis[u]=1;
    for(ll i=0;i<graph[u].size();i++)
    {
        ll v = graph[u][i];
        if(!vis[v])dfs(v,u);
    }
    tout[u]=++tim;
}
bool is_ancestor(ll u,ll v)
{
    if((tin[v]>=tin[u])&&(tout[u]>=tout[v]))return true;
    return false;
}
ll lca(ll u,ll v)
{
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i=l;i>=0;i--){
        if(!is_ancestor(up[u][i],v))
            u = up[u][i];}
    return up[u][0];
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,m;
   l=30;tim=0;
   cin>>n>>m;
   for(ll i=0;i<m;i++)
   {
       ll u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
    dfs(1,1);
    ll q;
    cin>>q;
    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
    

}