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
       ll arr2[n];
       ll sum=0,sum2=0;
       for(ll i = 0; i < n; i++)
       {
           cin>>arr[i];
           arr2[i]=arr[i]*arr[i];
       }
       sort(arr2,arr2+n);
       sort(arr,arr+n);
       
       for(ll i = 1; i <= k; i++)
       {
           arr[n-i]=1;
           arr2[n-i]=1;
       }
        
        for(ll i = 0; i < n; i++)
        {
            sum+=arr[i];
            sum2+=arr2[i];
        }
        if(sum>=sum2)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        
       
       
   }
}