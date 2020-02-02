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
   ll s;
   cin>>n>>s;
   ll arr[n];
   ll sum=0;
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i] ;
       sum+=arr[i]; 
   }
   if(sum<s)
   {cout<<"-1";return 0;}
   ll l=0,r=1e9,m;
   ll ans=0;
   while(l<=r)
   {
       m = (l+r)/2;
    //    cout<<m<<"\n";

       ll t = 0;
       ll flag=0;
       for(ll i = 0; i < n; i++)
       {
           if(arr[i]<m)
           {flag=1;break;}
           else
           t+=(arr[i]-m);
       }
       if(flag==0)
       {
           if(t>=s)
           {
               ans = m;
               l = m+1;
           }
           else
           {
               r = m-1;
           }
       }
       else
       {
           r = m-1;
       }
       
   }
   cout<<ans;
   
}