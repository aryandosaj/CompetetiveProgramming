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
ll n, c;
ll arr[1000006];
ll dp[1000006];
ll cost(ll x, ll y)
{
    return (x - y) * (x - y);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, c;
    cin >> n >> c;
    ll ans;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (i == 1)
        {
            dp[1] = 0;
            continue;
        }
        dp[i] = MAX;
        for (int j = 1; j < i; j++)
        {
            dp[i] = min(dp[i], cost(arr[j], arr[i]) + dp[j] + c);
        }
    }
    cout << dp[n];
}