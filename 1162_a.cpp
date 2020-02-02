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
   ll n,h,m;
   cin>>n>>h>>m;
   ll arr[n+1];
   for(ll i=1;i<=n;i++)arr[i]=h;
   for(ll i=0;i<m;i++)
   {
       ll l,r,x;
       cin>>l>>r>>x;
       for(l;l<=r;l++)
       {
           if(arr[l]>x)arr[l]=x;
       }
   }
   ll ans=0;
   for(ll i=1;i<=n;i++)ans+=arr[i]*arr[i];
   cout<<ans;
}