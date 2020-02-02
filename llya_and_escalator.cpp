#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
double dp[2001][2001];

int main()
{
    for (int i = 0; i < 2001; i++)
    {
        for (int j = 0; j < 2001; j++)
        {
            dp[i][j] = 0;
        }
    }

    // cout<<ncr(5,2);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    double n, p, t;
    cin >> n >> p >> t;
    dp[0][0] = 1;

    double ans = 0;
    for(int i=1;i<=t;i++)
    {
        
        for(int j=0;j<=n;j++)
        {
            
                // ans+=j*dp[i][j];
                // continue;
            if(j==n)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            dp[i][j]+=dp[i-1][j]*(1-p);
            if(j!=0)
            dp[i][j]+=dp[i-1][j-1]*p;
            if(i==t)
            ans+=j*dp[i][j];
            
            // cout<<dp[i][j]<<" ";
            

            
        }
        
    }
    printf("%0.6f",ans);
}