#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll m;
ll dp[(1 << 20)];
ll pos[20][20];
ll val[21];
ll rec(ll mask)
{
    if (dp[mask] != -1)
        return dp[mask];
    int p = __builtin_popcount(mask);
    if (p == m)
        return 0;
    ll ans = MAX;
    for (int i = 0; i < m; i++)
    {
        if ((1 << i) & mask)
            continue;
        ll temp = 0;
        for (int j = 0; j < m; j++)
        {
            if (j != i)
            {
                if ((1 << j) & mask)
                    temp += p * pos[i][j];
                else
                    temp -= p * pos[i][j];
            }
        }
        ans = min(temp + rec(((1 << i) | mask)), ans);
    }
    return dp[mask] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n >> m;
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << "0";
        return 0;
    }
    for (int i = 0; i < (1 << 20); i++)
        dp[i] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        pos[s[i] - 'a'][s[i + 1] - 'a']++;
        pos[s[i + 1] - 'a'][s[i] - 'a']++;
    }
    cout << rec(0);
}