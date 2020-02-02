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
   for(ll i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   sort(arr,arr+n);
   ll ans  = -arr[0];
   for(ll i=1;i<n;i++)ans+=arr[i];
   ll ans2 = arr[n-1];
   for(ll i=0;i<n-1;i++)ans2-=arr[i];
   cout<<max(abs(ans),abs(ans2));
}