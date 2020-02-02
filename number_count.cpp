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
unordered_map<ll, ll> mp;
ll dp[100005][11];
ll k;
ll rec(ll n, ll m)
{

    if (mp[m] == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (n == 1)
        return 1;
    ll ans = 0;
    for (ll i = 0; i < 10; i++)
    {
        if (abs(m - i) >= k)
            (ans += rec(n - 1, i)) %= MAX;
    }
    return dp[n][m] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        for (ll i = 0; i < 100005; i++)
            for (ll j = 0; j < 11; j++)
                dp[i][j] = -1;
        ll n, m;
        cin >> n >> m >> k;
        for (ll i = 0; i < m; i++)
        {
            ll x;
            cin >> x;
            mp[x] = 1;
        }
        ll ans = 0;
        for (ll i = 1; i < 10; i++)
        {
            (ans += rec(n, i)) %= MAX;
        }
        cout << ans << "\n";
    }
}