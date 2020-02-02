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
   ll x,y,z;
   cin>>x>>y>>z;
   if(x>y)
   {
       x-=y;
       if(x>z)cout<<"+";
       else cout<<"?";

   }
   else if(y>x)
   {
       y-=x;
       if(y>z)cout<<"-";
       else cout<<"?";
   }
   else
   {
       if(z==0)cout<<"0";
       else
       cout<<"?";
   }

}