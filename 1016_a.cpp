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
   ll n,m;
   cin>>n>>m;
   ll arr[n];
   ll left=0;
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i];
       if(arr[i]>=left)
       {
           arr[i]-=left;
           if(left>0)
           cout<<(arr[i]/m+1)<<" ";
           else
           cout<<(arr[i]/m)<<" ";
            if(arr[i]>m)
           left = m-arr[i]%m;
           else
           left=m-arr[i];
       }
       else 
       {
           left = left-arr[i];
           if(left==0)
           cout<<"1 ";
           else
           cout<<"0 ";

       }
       
   }
   
}