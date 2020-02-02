#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   ll s1=1,s2=1;
   for(ll i=0;i<n;i++)
   {
       ll x;cin>>x;
       s1 = (s1 *(1+x))%MAX;
       s2 = (s2 *(1-x))%MAX;
   }
   ll ans = ((s1+s2)*(power(2,MAX-2,MAX)) -1 +MAX)%MAX;
   cout<<ans;
}