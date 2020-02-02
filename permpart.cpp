#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vll dp[2000002];
ll arr[2000002];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       for(ll i=1;i<=2*n;i++)dp[i].clear(),dp[i].resize(2*n/i+1,0),arr[i]=0;
       ll ans=0;
       for(ll i=0;i<n;i++)
       {
           ll x;cin>>x;
           if(x>2*n)ans++;else arr[x]++;
       }
       for(ll i = dp[1].size()-1;i>=0;i--)
       {
           dp[1][i] = abs(arr[1]-i);
           if(i!=dp[1].size()-1) dp[1][i] = min(dp[1][i],dp[1][i+1]);
       }
       for(ll i=2;i<=2*n;i++)
       {
           ll s = dp[i].size()-1;
           for(ll j = s;j>=0;j--)
           {
               dp[i][j] = dp[i-1][j]+abs(arr[i]-j);
               if(j!=s) dp[i][j] = min(dp[i][j],dp[i][j+1]);
           }
       }
       cout<<ans+min(dp[2*n][0],dp[2*n][1])<<"\n";

   }
}