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
   ll arr[n+1];
   ll pre[n+1];pre[0]=0;
   map<ll,ll>mp;
   
   for(ll i=1;i<=n;i++)
   {
       cin>>arr[i];
       pre[i] = pre[i-1]^arr[i];
       mp[pre[i]]++;
   }
   if(pre[n]!=0){cout<<"0";return 0;}
   ll ans=0;
   for(auto i:mp)
   {
       ans+=power(2,i.second-1,MAX);ans=ans%MAX;
   }
   cout<<ans;
   

}