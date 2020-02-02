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

ll dp[101][101][130];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    ll k;
    cin >> s >> k;
    ll m;
    cin >> m;
    map<char, map<char, ll>> mp;

    for (ll i = 0; i < m; i++)
    {
        char u, v;
        ll w;
        cin >> u >> v >> w;
        mp[u][v] = w;
    }
    s=" "+s;
    memset(dp, 0, sizeof dp);
    for (ll i = 1; i <=s.length(); i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                for (char l = 'a'; l <= 'z'; l++)
                {
                    if (c != s[i])
                        dp[i][j][c] = max(max(dp[i][j][c], dp[i - 1][j - 1][l] + mp[l][c]),dp[i-1][j][l]+mp[l][s[i]]);
                    else
                        dp[i][j][c] = max(max(dp[i][j][c], dp[i - 1][j][l] + mp[l][c]),dp[i-1][j][l]+mp[l][s[i]]);
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 'a'; i <= 'z'; i++)
    {
        // if (s[s.length() - 1] != i)
            ans = max(ans, dp[s.length()][k][i]);
        // else
            // ans = max(ans, dp[s.length()][k][i]);
    }
    cout << ans;
}