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
   ll n,m;
   cin>>n>>m;
   vll sub[m+1];
   
   for(ll i = 0; i < n; i++)
   {
       ll s,r;
       cin>>s>>r;
       sub[s].push_back(r);
   }
   ll arr[m+1];
   
   for(ll i = 1; i <= m; i++)
   {
      sort(sub[i].begin(),sub[i].end(),greater<int>());
      arr[i]=0;
   }
   ll ans=0;
   ll s=0;
   for(ll i = 1; i <= m; i++)
   {
       s++;
       ll temp=0;
       if(sub[i].size()<s)
       continue;
       else
       {
           arr[i]+=sub[i][s-1];
           if(arr[i]>0)
           temp+=arr[i];
       }
   }
   
   
   
}