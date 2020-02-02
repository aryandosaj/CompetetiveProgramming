#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll n,m,d,max_d,haunted;
bool ans[100001];
ll level[100001];
vll graph[100001];
map<ll,ll>mp;
void dfs(ll u,ll p)
{
    level[u]=level[p]+1;
    ans[u]&=(level[u]<=d);
    if(mp[u]&&level[u]>max_d)
        max_d = level[u],haunted=u;
    
    for(ll i = 0; i < graph[u].size(); i++)
    {
        ll v=graph[u][i];
        if(v!=p)
        dfs(v,u);
    }    
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m>>d;
   ll hrr[m];
   for(int i = 0; i < 100001; i++)
   {
       ans[i]=1;
   }
   
   for(ll i = 0; i < m; i++)
   {
       cin>>haunted;
       mp[haunted]=1;
       hrr[i]=haunted;
   }
   
   for(ll i = 0; i < n-1; i++)
   {
       ll u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   level[0]=-1;
   dfs(haunted,0);
   dfs(haunted,0);
   dfs(haunted,0);
   dfs(haunted,0);
   ll c=0;
   for(int i = 1; i <=n; i++)
   {
       if(ans[i])
        c++;
   }
    cout<<c;

}