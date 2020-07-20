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
ll n, m;
string s, t;
ll dp[3003][3003];
ll rec(ll l, ll r, ll ind)
{
    if (l > r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];

    ll ans = 0;
    if (l >= m || s[ind] == t[l])
        ans = rec(l + 1, r, ind - 1);
    if (r >= m || s[ind] == t[r])
        ans = (ans + rec(l, r - 1, ind - 1)) % MOD;
    return dp[l][r] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = s.length();
    m = t.length();
    ll ans = 0;
    f(m - 1, n) ans = (ans + rec(0, i, i)) % MOD;
    cout << ans << "\n";
}