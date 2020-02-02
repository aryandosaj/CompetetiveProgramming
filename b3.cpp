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
ll dp[11][11];
string s;
ll rec(ll n, ll d)
{
    if (dp[n][d] != -1)
        return dp[n][d];
    ll ans = 0;
    if (n == 0)
        return s[n] - '0';
    for (ll i = 1; i <= 9; i++)
    {
        if (i <= s[n - 1] - '0')
            ans = max(ans, d * rec(n - 1, i));
        else
            ans = max(ans, (d - 1) * rec(n - 1, i));
    }
    return dp[n][d] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    ll ans = 0;
    for (ll i = 1; i <= s[i] - '0'; i++)
    {
        for (ll i = 0; i < 11; i++)
        for (ll j = 0; j < 11; j++)
            dp[i][j] = -1;
        ans = max(ans, rec(s.length() - 1, i));
    }
    cout << ans;
}