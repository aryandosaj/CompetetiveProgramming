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
   ll arr[2*n];
   ll f=0;
   for(ll i=0;i<2*n;i++)
       {cin>>arr[i];if((i!=0)&&(arr[i-1]!=arr[i]))f=1;}
    if(f)
    {
        sort(arr,arr+2*n);
   for(ll i=0;i<2*n;i++)
cout<<arr[i]<<" ";
    }
    else
    {
        cout<<"-1";
    }
    
    
}