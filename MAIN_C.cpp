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
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,k;
       cin>>n>>k;
       ll arr[n];
       
       for(ll i = 0; i < n; i++)
       {
           cin>>arr[i];
       }
       ll l=1;
       sort(arr,arr+n);
       ll r = arr[n-1];
       ll m=r;
       ll ans=0;
       while(l<=r)
       {
           ll sum=0;
           for(ll i = n-1; i >= 0; i--)
           {
               ll a = arr[i]/m;
               sum+=a;
           }
           if(sum>=k)
           l=m+1,ans=m;
           else
           r=m-1;
            m=(l+r)/2;   
       }
       cout<<ans<<"\n";
   }
}