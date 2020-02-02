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
   ll arr[2*n];
//    map<ll,ll> mp;
//    vll v;
   ll ans=-1;
   for(ll i = 0; i < 2*n; i++)
   {
       cin>>arr[i];
    //    if(mp[arr[i]]==0)
    //    v.push_back(arr[i]);
    //    mp[arr[i]]++;
       
       
   }
   sort(arr,arr+2*n);
//    sort(v.begin(),v.end());
   ll mi=(arr[n-1]-arr[0])*(arr[2*n-1]-arr[n]);
   
   
   for(ll i = 1; i <n; i++)
   {
    //    cout<<(arr[i+n-1]-arr[i])<<" ";
       mi = min(mi,(arr[i+n-1]-arr[i])*(arr[2*n-1]-arr[0]));
   }
  
//    cout<<((max1-min1))<<" "<<(mi);

   cout<<(mi);
   
   
   

   


   

}