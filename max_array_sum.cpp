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
   ll arr[n+1];
   ll dp[n+1];
   arr[0]=0;
   dp[0]=0;
   for(ll i = 1; i <= n; i++)
   {
       cin>>arr[i];

   }
   if(arr[1]>0)
   dp[1]=arr[1];
   else dp[1]=0;
   for(ll i=2;i<=n;i++)
   {
       dp[i] = max(dp[i-1],arr[i]+dp[i-2]);
   }
   cout<<dp[n];
}