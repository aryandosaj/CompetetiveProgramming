#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
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
#define MAX 100000000000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = " "+s;
    ll arr[n+1];
    arr[0]=0;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    ll dp[n + 1][5];
    for (ll i = 0; i < n+1; i++)
    {
        for (ll j = 0; j < 5; j++)
        {
            dp[i][j] = MAX;
            if(i==0) dp[i][j]=0;
        }
    }
    // dp[0][0]=0;
    string t = " hard";
    // dp[0][1]=0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= 4; j++)
        {
            if(s[i]==t[j])
            {
                dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]);
                // dp[i][j+1] = min(dp[i][j+1],)
            }
            else dp[i][j]=min(dp[i][j],dp[i-1][j]);
            dp[i][j] = min(dp[i][j],dp[i-1][j]+arr[i]);
            // cout<<dp[i][j]<<" ";
        }
    }
    ll m=MAX;
    for(ll i=1;i<=4;i++) m = min(m,dp[n][i]);
    cout<<m;
}