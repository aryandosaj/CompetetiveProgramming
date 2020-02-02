#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 998244353
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   ll arr[n];
   map<ll,ll>mp;
   for(ll i=0;i<n;i++)
   {
       cin>>arr[i];mp[arr[i]]=i;
   }
   ll mm=mp[arr[0]];ll c=0;
   for(ll i=0;i<=mm;i++)
   {
       if(i==n-1)break;
       if(i==mm){c++,mm=mp[arr[i+1]];continue;}
       mm = max(mm,mp[arr[i]]);
   }
   cout<<power(2,c,MAX);
}