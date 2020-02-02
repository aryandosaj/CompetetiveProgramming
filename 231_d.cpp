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
   ll arr[7];
   ll x,y,z;
   ll x1,y1,z1;
   cin>>x>>y>>z>>x1>>y1>>z1;
   for(ll i=0;i<6;i++)cin>>arr[i+1];
   ll ans=0;
   if(x>x1) ans+=arr[6];
   if(x<0)ans+=arr[5];
   if(y>y1)ans+=arr[2];
   if(y<0)ans+=arr[1];
   if(z>z1)ans+=arr[4];
   if(z<0) ans+=arr[3];
   cout<<ans;
}