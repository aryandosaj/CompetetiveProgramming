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
   for(ll i=1;i<=n;i++)
   cin>>arr[i];
   ll q;
   cin>>q;
   ll mm=0;
   vll v;
   while(q--)
   {
       ll t;
       cin>>t;
       if(t==1)
       {
           ll p,x;
           cin>>p>>x;
           arr[p]=x;
       }
       else if(t==2){
           ll x;
           cin>>x;
           mm = max(mm,x); 
       }
   }
}