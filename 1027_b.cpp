#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
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
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
   ll n;
   ll q;
   cin>>n>>q;
   if(n%2==0)
   {
       
       for(ll i = 0; i < q; i++)
       {
           ll r,c;
           cin>>r>>c;
           if((r+c)%2==0)
           {
               ld cc = (ld)c;
               cout<<((r-1)*n/2+(ll)ceil(cc/2))<<"\n";
           }
           else
           {
               ld cc = (ld)c;
               cout<<(n*n/2+(r-1)*n/2+(ll)ceil(cc/2))<<"\n";
           }
       }
   }
   else
   {
        for(ll i = 0; i < q; i++)
       {
           ll r,c;
           cin>>r>>c;
           if((r+c)%2==0)
           {
               ld cc = (ld)c;
               ll temp = (r-1)/2*n;
               if((r-1)%2==1)
               temp+=n/2+1;
               cout<<(temp+(ll)ceil(cc/2))<<"\n";
           }
           else
           {
               ll temp = ((r-1)/2)*n+(n*n)/2+1;
               if((r-1)%2==1)
               temp+=n/2;
               ld cc = (ld)c;
               cout<<(temp+(ll)ceil(cc/2))<<"\n";
           }
       }
   }
}