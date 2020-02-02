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
   ll n,a,x,b,y;
   cin>>n>>a>>x>>b>>y;
   while(1)
   {
       if(a==b){cout<<"YES";return 0;}
       if(a==x)break;if(b==y)break;
       if(a!=n)a++;else a=1;
       if(b!=1)b--;else b=n;

   }
   cout<<"NO";
}