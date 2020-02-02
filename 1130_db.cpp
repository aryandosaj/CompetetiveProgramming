#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vll a[100005];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   a[0].push_back(0);
   a[0].push_back(0);
   for(ll i=0;i<2*n;i++)
   {
       ll x;
       cin>>x;a[x].push_back(i);
   }
   ll ans=0;
   for(ll i=1;i<=n;i++)
   {
       ans+=min(abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1]),abs(a[i][0]-a[i-1][1])+abs(a[i][1]-a[i-1][0]));
   }
   cout<<ans;
}