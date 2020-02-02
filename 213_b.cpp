#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll arr[10];
ll fac[201];
ll dp[201][10];
ll invmod(ll n)
{
    return power(n,MAX-2,MAX);
}
ll c(ll n,ll r)
{
    if(r>n)return 0;
    ll sum = (((fac[n]*invmod(fac[r]))%MAX)*invmod(fac[n-r]))%MAX;
}
ll post[11];

ll f(ll l,ll n)
{
    if(dp[l][n]!=-1)return dp[l][n];
    if(arr[n]>l)return 0;
    if(l<0)return 0;
    if(post[n]==0)return 1;    
    ll sum=0;
    for(ll i=arr[n];i<=l;i++)
    {
        sum+=f(l-i,n+1)*c(l,i);
        sum%=MAX;
    }
    cout<<l<<" "<<n<<" "<<sum<<"\n";
    return dp[l][n]=sum;
}
ll f0(ll l)
{
    ll sum=0;
    for(ll i = arr[0];i<=l;i++)
    {
        ll x =f(l-i,1)*c(l-1,i) ;
        sum+=x;
        sum%=MAX;
    }
    return sum;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   for(ll i=0;i<201;i++)
       for(ll j=0;j<10;j++)
        dp[i][j]=-1;
   fac[0]=1;
   for(ll i=1;i<=200;i++)
        fac[i] = (fac[i-1]*i)%MAX;
    
   ll n;
   cin>>n;
   for(ll i=0;i<10;i++)
   cin>>arr[i];
   for(ll i=9;i>=0;i--)
   {
       post[i]=post[i+1]+arr[i];
   }
   cout<<f0(n);

}