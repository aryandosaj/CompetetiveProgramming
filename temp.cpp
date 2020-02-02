#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAX 1000000007
ll weight[101], cost[101];
ll n, m;
ll dp[101][10004];
ll rec(ll i, ll j)
{
    if (j < 0)
        return -MAX;
    if (i == m)
        return 0; 
    if (dp[i][j] != -1)
        return dp[i][j];
    for(int k=0;k<=j/weight[i];k++)
        dp[i][j] = max(dp[i][j], rec(i + 1, j - cost[i]*k) + weight[i]*k);
    return dp[i][j];
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> cost[i] >> weight[i];
    }
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    cout << rec(0, n);
}