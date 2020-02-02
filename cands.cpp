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
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,m;
       cin>>m>>n;
       ll arr[n];
       for(ll i=0;i<n;i++)
       cin>>arr[i];
       ll low=0,high=200000,mid;
       ll c=0;
       ll ans=0;
       while(low<=high)
       {
           c=m;
           mid = (low+high)/2;
           for(ll i=0;i<n;i++)
           {
               if(arr[i]>=mid)
                c-=(arr[i]/mid);
                if(arr[i]%mid)c--;
           }
           if(c>=0)
            high = mid-1,ans=mid;
           else
               low = mid+1;
           
       }
       cout<<ans<<"\n";
   }
}