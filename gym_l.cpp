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
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   ll arr[n+2];
   
   for(ll i = 0; i <= n+1; i++)
   {

       arr[i]=0;
   }
   
   for(ll i = 0; i < n; i++)
   {
       ll a,b;
       cin>>a>>b;
       arr[a]++;arr[b+1]--;
   }
   
   for(ll i = 1; i <= n+1; i++)
   {
       arr[i]=arr[i-1]+arr[i];
   }
   
   ll ans=0;
   for(ll i = 1; i <= n; i++)
   {
       if(arr[i]==i)
       ans=max(i,ans);
   }
   if(ans)
   cout<<ans;
   else
   cout<<"-1";
   
   
}