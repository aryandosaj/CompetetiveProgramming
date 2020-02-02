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
string s;
int n;
ll dp[1001][26];
ll rec(int i, char c)
{
    // cout<<i<<" "<<c<<"\n";
    if (i == n)
    {
        if (c == s[0])
            return 1;
        return 0;
    }
    if (c != '-' && dp[i][c - 'a'] != -1)
        return dp[i][c - 'a'];
    ll ans = 0;
    if (s[i] == '?')
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            if (c != j)
                ans += rec(i + 1, j);
            ans = ans % MAX;
        }
    }
    else
    {
        if (c == s[i])
            return 0;
        ans = rec(i + 1, s[i]);
    }
    ans = ans % MAX;
    if (c != '-')
        return dp[i][c - 'a'] = ans;
    else
        return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 26; j++)
                dp[i][j] = -1;
        cin >> s;
        n = s.length();
        cout << rec(0, '-') % MAX << "\n";
    }
}