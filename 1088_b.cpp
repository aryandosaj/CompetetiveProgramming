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
   
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i]; 
   }
   sort(arr,arr+n);
   ll c=0;
   ll u=0;
   for(ll i = 0; i < n; i++)
   {
       if((arr[i]-c)==0)
       continue;
       else
       {
           cout<<arr[i]-c<<"\n";
           c += arr[i]-c;
           u++;
           if(u>=k)
           return 0;
       }
   }
   
   for(ll i = u; i < k; i++)
   {
       cout<<"0"<<"\n";
   }
   
   
   
}