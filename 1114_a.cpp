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
   ll x,y,z,a,b,c;
   cin>>x>>y>>z>>a>>b>>c;
   if((x+y+z)>(a+b+c)){cout<<"NO";return 0;}
   if(a>=x)
   {
       a-=x;
       if((a+b)>=y)
       {
           ll e = a+b -y+c;
           if(e>=z)
           {
               cout<<"YES";return 0;
           }
       }
   }
   cout<<"NO";
}