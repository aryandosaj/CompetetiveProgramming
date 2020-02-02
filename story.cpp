#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll n;
ll arr[1005];
ll dp[1005][1005];
ll fun(ll i,ll k)
{
    if(i==n)return 0;
    if(dp[i][k]!=-1)
    return dp[i][k];
    return dp[i][k] = max(fun(i+1,k+1)+arr[i]*k,fun(i+1,k));
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   
   cin>>n;
   for(int i=0;i<n;i++)cin>>arr[i];
    return fun(0,1);
   
}