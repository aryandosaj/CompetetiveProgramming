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
ll lcs[1001][1001];
ll dp[1001];
ll dp2[1001];
ll ml[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    ll ans = 0;

    cin >> s1 >> s2;
    {
        string rs;
        rs = s2;
        ll n = s1.length();
        ll m = s2.length();
        ll len, ii, jj;
        len = 0;
        reverse(rs.begin(), rs.end());

        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    lcs[i][j] = 0;
                else if (s1[i - 1] == rs[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (len < lcs[i][j])
                {
                    ii = i;
                    jj = j;
                    len = lcs[i][j];
                }
                if (i)
                    ml[i - 1] = max(ml[i - 1], lcs[i][j]);
                // cout<<lcs[i][j]<<" ";
            }
            // cout<<"\n";
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (i + j < n && i - j >= 0)
                    if (s1[i + j] == s1[i - j])
                        dp[i]++;
                    else
                        break;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (s1[i] == s1[i + 1])
            {
                for (ll j = 0; j < n; j++)
                {
                    if (i - j >= 0 && i + j < n)
                        if (s1[i - j] == s1[i + 1 + j])
                            dp2[i]++;
                        else
                            break;
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (i - dp[i] >= 0)
                ans = max(ml[i - dp[i]] * 2 + 2 * dp[i] - 1, ans);
            if (i - dp2[i] >= 0)
                ans = max(ans, ml[i - dp2[i]] * 2 + 2 * dp2[i]);
        }
    }
    {
        for (ll i = 0; i < 1001; i++)
        {
            dp[i] = 0;
            dp2[i] = 0;
            ml[i] = 0;
            for (ll j = 0; j < 1001; j++)
            {
                lcs[i][j] = 0;
            }
        }
        reverse(s2.begin(), s2.end());
        reverse(s1.begin(), s1.end());
        swap(s1, s2);
        string rs;
        rs = s2;
        ll n = s1.length();
        ll m = s2.length();
        ll len, ii, jj;
        len = 0;
        reverse(rs.begin(), rs.end());

        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    lcs[i][j] = 0;
                else if (s1[i - 1] == rs[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (len < lcs[i][j])
                {
                    ii = i;
                    jj = j;
                    len = lcs[i][j];
                }
                if (i)
                    ml[i - 1] = max(ml[i - 1], lcs[i][j]);
                // cout<<lcs[i][j]<<" ";
            }
            // cout<<"\n";
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (i + j < n && i - j >= 0)
                    if (s1[i + j] == s1[i - j])
                        dp[i]++;
                    else
                        break;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (s1[i] == s1[i + 1])
            {
                for (ll j = 0; j < n; j++)
                {
                    if (i - j >= 0 && i + j < n)
                        if (s1[i - j] == s1[i + 1 + j])
                            dp2[i]++;
                        else
                            break;
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (i - dp[i] >= 0)
                ans = max(ml[i - dp[i]] * 2 + 2 * dp[i] - 1, ans);
            if (i - dp2[i] >= 0)
                ans = max(ans, ml[i - dp2[i]] * 2 + 2 * dp2[i]);
        }
    }
    cout << ans;
}