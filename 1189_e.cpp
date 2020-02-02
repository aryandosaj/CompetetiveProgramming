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
   ll n,p,k;
   cin>>n>>p>>k;
   ll arr[n];
   map<ll,ll>mp;
   for(int i=0;i<n;i++)cin>>arr[i],arr[i] = (power(arr[i],4,p)-k*arr[i]+p*p)%p,mp[arr[i]]++;
   ll ans=0;
   for(auto i:mp)
   {
       ans+=(i.second*(i.second-1))/2;
   }
   cout<<ans;
   
}