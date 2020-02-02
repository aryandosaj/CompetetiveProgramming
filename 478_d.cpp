#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll dp[200005];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll a,b,h;
   cin>>a>>b;
   dp[0]=1;dp[1]=1;
   for(h=2;h*(h+1)/2<=(a+b);h++)
   {
       for(ll i = a;i>=h;i--)
       {
           (dp[i]+=dp[i-h])%=MAX;
       }
   }
   ll ans=0;
   for(ll i=0;i<=a;i++)
   {
       if((((h)*(h-1))/2)-i<=b)(ans+=dp[i])%=MAX;
   }
   cout<<ans;
   
}