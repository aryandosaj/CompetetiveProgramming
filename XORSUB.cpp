#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
int arr[1001];
int dp[1025][1001];
int n,k;
int fun(int mask,int i)
{
    if(i==n)return mask^k;
    if(dp[mask][i]!=-1)return dp[mask][i];
    return dp[mask][i] = max(fun(mask^arr[i],i+1),fun(mask,i+1));

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<1025;i++)for(int j=0;j<1001;j++)dp[i][j]=-1;
        cin>>n>>k;
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        cout<<fun(0,0)<<"\n";

    }
}