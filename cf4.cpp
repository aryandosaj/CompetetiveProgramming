#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll dp[5001][5001];
ll xrr[5001];
ll calc(ll len,ll start)
{
    ll end=start+len-1;
    ll val = xrr[start-1]^xrr[end];
    return val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    ll arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(i==0)
        xrr[i]=arr[i];
        else
        xrr[i]=xrr[i-1]^arr[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==1)
            {dp[i][j]=calc(i,j);continue;}
            dp[i][j]=max(max(dp[i-1][j],dp[i-1][j+1]),calc(i,j));
        }
        
    }
    ll q;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        cout<<dp[r-l+1][l]<<"\n";
    }
    
    

    
}