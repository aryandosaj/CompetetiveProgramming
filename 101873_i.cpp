#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll arr[300050];
ll dp[300050];
ll n,k;
ll rec(ll i)
{
    if(dp[i]!=-1)return dp[i];
    if(i>n)return 0;
    ll ans = max(rec(i+1),arr[i]+rec(i+k));
    return dp[i]=ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<300005;i++)dp[i]=-1;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>arr[i];
    cout<<rec(k+1);
    
}