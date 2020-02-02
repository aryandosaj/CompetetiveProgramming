
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
ll dp[5001][5001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = m - 1; j >= 0; j--)
        {
            if (s[i][j] == '1')
                dp[j][i] = dp[j + 1][i] + 1;
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j <m; j++)
    //     {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << "\n";
    // }
    for (ll i = 0; i < m; i++)
        sort(dp[i], dp[i] + n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            // cout<<dp[j][i]<<" "<<(n-i)<<"=";
            ans = max(ans, dp[j][i] * (n - i));
        }
    }
    cout << ans;
}