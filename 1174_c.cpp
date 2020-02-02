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
   ll n;cin>>n;
   unordered_map<ll,ll>mp;
   unordered_map<ll,ll>prime;
   
   ll last=0;
   for(ll i=2;i<=n;i++)
   {
       if(!prime[i])
       {
           mp[i]=last+1;
           for(ll j=2;i*j<=n;j++)
           {
               prime[j*i]=1;
               if(mp[j*i]==0)
               mp[j*i]=last+1;
           }
           last++;
       }
   }
   for(ll i=2;i<=n;i++)
   cout<<mp[i]<<" ";
}