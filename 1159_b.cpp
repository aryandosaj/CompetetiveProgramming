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
   pair<ll,ll> arr[n];
   for(ll i=0;i<n;i++)
   cin>>arr[i].first,arr[i].second=i;
   sort(arr,arr+n);
   ll k=MAX;
   for(ll i=0;i<n;i++)
   {
       ll ind = arr[i].second;
       k = min(k,arr[i].first/(max(n-1-ind,ind)));
        
   }
   cout<<k;
}