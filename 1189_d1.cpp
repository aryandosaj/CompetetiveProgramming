#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int graph[100005];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   for(int i=1;i<n;i++)
   {
       ll u,v;
       cin>>u>>v;
       graph[u]++;graph[v]++;
   }
   for(int i=1;i<=n;i++)
   {
       if(graph[i]==2)
       {
           cout<<"NO";return 0;
       }
   }
   cout<<"YES";
}