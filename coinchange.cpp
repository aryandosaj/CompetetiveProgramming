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
   ll n;
   ll c;
   cin>>n>>c;
   ll arr[c];
   for(ll i = 0; i < c; i++)
   {
       cin>>arr[i];
   }
   ll dp[n+1];
   
   for(ll i = 0; i < n+1; i++)
   {
       dp[i]=0;
   }
   
   dp[0]=1;
   for(ll i = 0; i < c; i++)
   {
       
       for(ll j = arr[i]; j <= n ; j++)
       {
           dp[j] +=dp[j-arr[i]]; 
       }
       
   }
   cout<<dp[n];
   
   
}