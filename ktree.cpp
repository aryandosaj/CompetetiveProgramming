#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll dp[101][101];
ll ncr(ll n,ll r)
{
    if(n==r)
    return 1;
    if(r==0)
    return 1;
    if(r==1)
    return n;
    if(dp[n][r]!=-1)
    return dp[n][r];
    return dp[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            dp[i][j]=-1;
        }
    }
    
    ll n,k,d;
    cin>>n>>k>>d;
    ll sum=0;
    ll sub=0;
    for(int i = 1; i <= n; i++)
    {
        if((n-i+1)<d)
        sum+=(ncr(n-1,i-1);
        if(n-i-k>=0)
        {
            sub=i*ncr(n-k-1,i-1);
            sum=sum-sub;
        }
    }
    cout<<sum;
    
}