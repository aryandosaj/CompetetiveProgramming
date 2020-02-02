#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll prod(ll n)
{
    ll ans=1;
    while(n>0)
    ans*=n%10,n/=10;
    return ans;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   ll ans=0;
   for(n;n>=1;n--)
   {
       ans = max(ans,prod(n));
   }
   cout<<ans;
}