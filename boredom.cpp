#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll sum[100001];
ll dp[100001][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    ll arr[n];
    
    
    
    for(ll i = 0; i <= 100000; i++)
    {
        sum[i]=0;
    }

    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum[arr[i]]+=arr[i];
    }
    ll m=0;
    
    sort(arr,arr+n,greater<ll>());
    dp[100000][0]=0;
    dp[100000-1][0]=sum[100000];
    dp[100000][1]=sum[100000];
    dp[100000-1][1]=sum[100000-1];
    // cout<<dp[n][0]<<" "<<dp[n-1][0]<<" "<<dp[n][1]<<" "<<dp[n-1][0]<<" ";

    for(ll i = 2; i < 100001; i++)
    {
        dp[100000-i][0]=max(dp[100000-i+1][1],dp[100000-i+2][1]);
        dp[100000-i][1]=max(dp[100000-i+1][0],dp[100000-i+2][1])+sum[100000-i];

    }
    m=max(dp[1][0],dp[1][1]);
    cout<<m;
    
    
}