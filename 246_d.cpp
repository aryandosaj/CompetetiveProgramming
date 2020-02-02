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
// vll graph[100001];
set <ll> color[100001];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,m;
   cin>>n>>m;
   ll col[n+1];
   for(int i = 1; i <= n; i++)
   {
       cin>>col[i];
   }
   
   for(ll i = 0; i < m; i++)
   {
       ll a,b;
       cin>>a>>b;
    //    graph[a].push_back(b);
    //    graph[b].push_back(a);
    if(col[b]!=col[a])
       {color[col[a]].insert(col[b]);
       color[col[b]].insert(col[a]);}
   }
   ll mm=0;
   ll ans=MAX;
   for(ll i = 1; i <= n; i++)
   {
       if(mm<color[col[i]].size())
       {
           ans=col[i];
           mm=color[col[i]].size();
       }
       if((mm==color[col[i]].size())&&(ans>col[i]))
       {
           ans=col[i];
       }
   }
   cout<<ans;

   

}