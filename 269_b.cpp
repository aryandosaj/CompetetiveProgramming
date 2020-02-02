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
#define MAX 1000000007
ll dp[5001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll arr[n + 1];
    for (ll i = 0; i < n; i++)
    {
        ld x;
        cin >> arr[i + 1] >> x;
    }
    // dp[0]=0;
    // arr[0] = 0;
    ll ans = 0, mm;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = arr[i]; j >= 1; j--)
        {
            dp[arr[i]] = max(dp[arr[i]], dp[j]+1);
        }
    }
    for (ll j = 1; j <= m; j++)
    {
        ans = max(ans, dp[j]);
    }
    cout << n - ans;
}