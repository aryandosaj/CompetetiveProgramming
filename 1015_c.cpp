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
   ll brr[n];
   ll diff[n];
   ll total=0;
   ll mi = 0;
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i]>>brr[i];
       diff[i]=arr[i]-brr[i];
       total+=arr[i];
       mi+=brr[i];

   }
   if(mi>m)
   {
       cout<<"-1";return 0;
   }
   if(mi==m)
   {
       cout<<n;return 0;
   }
   sort(diff,diff+n);
    
    if(total<=m)
        {
            cout<<"0";return 0;
        }
    for(ll i = n-1; i >= 0; i--)
    {
        total-=diff[i];
        if(total<=m)
        {
            cout<<(n-i);return 0;
        }
    }
    
   
}