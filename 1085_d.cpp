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
   ll n;double s;
   cin>>n>>s;
   vll graph[n+1];
   for(ll i=1;i<n;i++) 
   {
       ll u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   double c=0;
   for(ll i=1;i<=n;i++) if(graph[i].size()==1)c++;
    double ans = s/c*2;
    cout<<setprecision(15);
    cout<<ans;

}