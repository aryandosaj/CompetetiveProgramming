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
   vll graph[1001];

ll visit[1000]={0};
void dfs(ll u){
    visit[u]=1;
    cout<<u<<" ";
    
    for(ll  i = 0; i < graph[u].size()  ; i++)
    {
        ll v = graph[u][i];
        if(visit[v])
        continue;
        else
        {
            dfs(v);
        }
    }
    
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   ll m;
   cin>>n>>m;
   
   for(ll i = 0; i < m; i++)
   {
       ll u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   
//    for(ll i = 1; i <= n; i++)
//    {
//        cout<<i<<"->";
//        for(ll j = 0; j < graph[i].size(); j++)
//        {
//            cout<<graph[i][j]<<" ";
//        }
//        cout<<"\n";
       
//    }
dfs(1);
   

   
}