#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   string s;cin>>s;s = " "+s;
   string l[n+1];
   for(ll i=0;i<=n;i++)l[i]="";
   vll graph[n+1];
   for(ll i=0;i<n-1;i++)
   {
       ll u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   queue<ll>q;q.push(1);
   unordered_map<ll,ll>vis;
   unordered_map<ll,ll>lev;
   vis[1]=1;
   while(!q.empty())
   {
       ll u = q.front();q.pop();
       vis[u]=1;
       l[lev[u]].push_back(s[u]);
       for(ll i=0;i<graph[u].size();i++)
       {
           ll v = graph[u][i];
           if(!vis[v])
           {
               lev[v] = lev[u]+1;
               q.push(v);
               
           }
       }
   }
   ll ans=0;
   for(ll i=0;i<=n;i++)
   {
       ll o=0,c=0;
    //    cout<<l[i]<<"\n";
       for(ll j=0;j<l[i].length();j++)
       {
           if(l[i][j]=='(')o++;else if(l[i][j]==')')c++;
       }
       
       ans+=min(o,c);
   }
   cout<<ans;

}