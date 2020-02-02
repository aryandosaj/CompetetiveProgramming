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
ll arr[101][101];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,m;
   cin>>n>>m;
   ll r[n+1],c[m+1];
   ll x=0;
   for(ll i = 1; i <= n; i++)
   {
       cin>>r[i];
       x=x^r[i];
   }
   
   for(ll i = 1; i <= m; i++)
   {
       cin>>c[i];
       x=x^c[i];
   }
   if(x!=0)
   {
       cout<<"NO";
       return 0;
   }
   ll rr[m+1];
   
   for(ll i = 0; i < m+1; i++)
   {
       rr[i]=0;
   }
   
   ll xr=0;
   for(ll i = 1; i <= n-1; i++)
   {
       xr=0;
       for(ll j = 1; j < m; j++)
       {
           xr=xr^j;
           arr[i][j]=j;
           rr[j]=rr[j]^arr[i][j];
       }
    //    cout<<xr<<" ";

       arr[i][m]=r[i]^xr;
       rr[m]=rr[m]^arr[i][m];
   }
   
   for(ll i = 1; i <= m; i++)
   {
    //    cout<<r[i]<<" "<<rr[i];
       arr[n][i]=rr[i]^c[i];
   }
   cout<<"YES\n";
   
   for(ll i = 1; i <= n; i++)
   {
       
       for(ll j = 1; j <= m; j++)
       {
           cout<<arr[i][j]<<" ";
       }
       cout<<"\n";
       
   }
   
   

   
   

   
}