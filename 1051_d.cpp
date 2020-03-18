#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 998244353
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
ll n, k;
ll dp[1001][2001][4];
ll rec(ll i, ll p, ll c)
{
    if (p > k)
        return 0;
    if (dp[i][p][c] != -1)
        return dp[i][p][c];
    if (i == n)
    {
        if (p == k)
            return 1;
        return 0;
    }
    // cout << i << " " << p << " " << c << "\n";
    ll ans = 0;
    if (c == 0)
        ans = (ans + rec(i + 1, p + 1, 1) + rec(i + 1, p + 1, 2) + rec(i + 1, p + 1, 3) + rec(i + 1, p, 0)) % MOD;
    else if (c == 1)
        ans = (ans + rec(i + 1, p, 1) + rec(i + 1, p + 2, 2) + rec(i + 1, p, 3) + rec(i + 1, p, 0)) % MOD;
    else if (c == 2)
        ans = (ans + rec(i + 1, p + 2, 1) + rec(i + 1, p, 2) + rec(i + 1, p, 3) + rec(i + 1, p, 0)) % MOD;
    else
        ans = (ans + rec(i + 1, p + 1, 1) + rec(i + 1, p + 1, 2) + rec(i + 1, p, 3) + rec(i + 1, p + 1, 0)) % MOD;
    return dp[i][p][c] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    f(0, 1001) fi(0, 2001) fii(0, 4) dp[i][j][k] = -1;
    ll ans = (rec(1, 1, 3)+rec(1,1,0)+rec(1,2,1)+rec(1,2,2)) % MOD;
    cout << ans << "\n";
}