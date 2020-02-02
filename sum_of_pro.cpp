#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll dp[3001][3001];
ll arr[3001];
ll rec(ll n,ll k)
{
    if(dp[n][k]!=-1)return dp[n][k];
    if(k==0)return 1;
    if(n==0) return 0;
    return dp[n][k] = ((arr[n]*rec(n-1,k-1))%MAX+rec(n-1,k))%MAX;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
       for(ll i=0;i<3001;i++)for(ll j=0;j<3001;j++)dp[i][j]=-1;
       ll n,k;
       cin>>n>>k;
       for(ll i=1;i<=n;i++)cin>>arr[i];
       ll ans=0;
       for(ll i=1;i<=k;i++)
       {
           (ans+=rec(n,i))%=MAX;
       }
       cout<<ans<<"\n";

   }
}