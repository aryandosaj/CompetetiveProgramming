#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
   ll m =0;
   ll c[n];
   m=arr[n-1];
   for(ll i = n-1; i >=1; i--)
   {
       m=max(arr[i],m);
       c[i-1]=m;
   }
   
   
   for(ll i = 0; i < n-1; i++)
   {
       if(c[i]>arr[i])
       cout<<c[i]-arr[i]+1<<" ";
       else if(c[i]==arr[i])
       cout<<"1 ";
       else
       cout<<"0 ";
   }
   cout<<"0";
   
   
}