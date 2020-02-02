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
   cin>>n;
   ll arr[n];
   
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i]; 
   }
   ll ans1=MAX;
   ll ans=0;
   for(ll c = 0; c < n; c++)
   {
       ans=0;
       for(ll i = 0; i < n; i++)
       {
           ans += (arr[i]*(i+abs(i-c)+c));
       }
       ans1 = min(ans,ans1);
       
   }
   cout<<ans1*2;
   
}