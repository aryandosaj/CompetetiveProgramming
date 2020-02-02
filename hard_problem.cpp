#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    // string s1="aaa";
    // string s2="abc";
    // cout<<s2.compare(s1);
    ll n;
    cin>>n;
    ll arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    string s[n];
    string rs[n];
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
        rs[i]=s[i];
        reverse(rs[i].begin(),rs[i].end());
    }
    ll dp[n][2];
    dp[0][0]=0;
    dp[0][1]=arr[0];
    for(int i = 1; i < n; i++)
    {
        dp[i][0]=100000000000000000;
        dp[i][1]=100000000000000000;
        // s1.compare(s2);less than 0
        if(s[i-1].compare(s[i])<=0)
        {
            dp[i][0]=dp[i-1][0];
        }
        if(rs[i-1].compare(s[i])<=0)
        {
            dp[i][0]=min(dp[i-1][1],dp[i][0]);
        }
        if(s[i-1].compare(rs[i])<=0)
        {
            dp[i][1]=dp[i-1][0]+arr[i];
        }
        if(rs[i-1].compare(rs[i])<=0)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+arr[i]);
        }        
    }
    ll ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans==100000000000000000)
    cout<<"-1";
    else
    cout<<ans;
}
