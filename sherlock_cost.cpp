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
   ll t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       ll b[n];
       
       for(ll i = 0; i < n; i++)
       {
           cin>>b[i];
       }
       ll dp[n+1][2];
       dp[0][0]=0;
       dp[0][1]=0;
       
       for(ll i = 1; i < n; i++)
       {
           dp[i][0]=max(dp[i-1][1]+abs(b[i-1]-1),dp[i-1][0]);
           dp[i][1]=max(dp[i-1][0]+abs(b[i]-1),dp[i-1][1]+abs(b[i]-b[i-1]));
       }
       cout<<max(dp[n-1][0],dp[n-1][1])<<"\n";
       
   }
}