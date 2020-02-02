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
   ll n,k;
   cin>>n>>k;
   ll arr[n];
   for(ll i=0;i<n;i++)
   cin>>arr[i];
   ll low=1,high=1e18,mid,ans=-1;
   while(low<=high)
   {
       mid = (low+high)/2;
       ll temp=0;
       for(ll i=0;i<n;i++)
       {
           temp+=arr[i]/mid;
       }
       if(temp>=k)
       {
           ans=mid;low = mid+1;
       }
       else
       {
           high = mid-1;
       }
       
   }
   cout<<ans;
}