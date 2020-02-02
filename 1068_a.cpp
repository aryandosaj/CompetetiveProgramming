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
   ll n,m,k,l;
   cin>>n>>m>>k>>l;
   l+=k;
   if(m>n)
   {
       cout<<"-1";
   }
   else
   {
       ll x = (l%m==0)?(l/m):(l/m)+1;
       if((x*m)<=(n))
       cout<<x;
       else
       cout<<"-1";
   }

   
}