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
vll graph[100001];
ll level[100001];
bool visit[100001];
vll lev[100001];
ll m=0;
ll ans=0;
ll arr[100001];
ll incr[100001];
ll decr[100001];
void dfs(ll u,ll p)
{   
    for(ll i = 0; i < graph[u].size(); i++)
    {
        ll v  = graph[u][i];
        if(v==p)
        continue;
        else
        {
            dfs(v,u);
            incr[u]=max(incr[v],incr[u]);
            decr[u]=max(decr[u],decr[v]);
        }
    }
    ll temp=arr[u]+incr[u]-decr[u];
    if(temp<0)incr[u]+=-temp;else decr[u]+=temp;
    // cout<<temp<<" ";
    
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   for(ll i = 0; i < n-1; i++)
   {
       ll u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   
   for(ll i = 1; i <= n; i++)
   {
       cin>>arr[i];
   }
   
   for(ll i = 0; i < 100001; i++)
   {
       incr[i]=0;
       decr[i]=0;
   }
   arr[0]=0;
   dfs(1,0);
//    ll carry=0;
//    ll ans=0;
//    for(ll i = m; i >=0; i--)
//    {
       
//        for(ll j = 0; j < lev[i].size(); j++)
//        {
//            ans+=abs(arr[lev[i][j]]+carry);
//            carry+=-1*(arr[lev[i][j]]+carry);
//        }
//    }
   cout<<incr[1]+decr[1];

   
}