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
#define MAX 100000000
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    ll dp[101][101][2];
    
    for(ll i = 0; i < 101; i++)
    {
        for(ll j = 0; j < 101; j++)
        {
            dp[i][j][0]=0;
            dp[i][j][1]=0;
        }
    }
    
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    
    for (ll i = 0; i <= n1; i++)
    {
        for (ll j = 0; j <= n2; j++)
        {
            for (ll k = 1; (k <= k1) && (k <= i); k++)
            {
                dp[i][j][0] += dp[i - k][j][1];
                dp[i][j][0] %= MAX;
            }
            for (ll k = 1; (k <= k2) && (k <= j); k++)
            {
                dp[i][j][1] += dp[i][j - k][0];
                dp[i][j][1] %= MAX;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1])%MAX;
}