#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
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
ll w[81][81];
ll dp[81][10][2];
ll a[81];
ll rec(ll u, ll k, ll c)
{
    if ((a[u] != -1) && (a[u] != c))
        return MOD;
    else
        a[u] = c;
    if (dp[u][k][c] != -1)
        return dp[u][k][c];
    if (u == 1 && k == 0)
        return 0;
    if (k == 0)
        return MOD;
    ll ans = MOD;
    f(1, n + 1)
    {
        if (i != u)
            ans = min(ans, rec(i, k - 1, 1 - c) + w[u][i]);
    }
    a[u] = -1;
    return dp[u][k][c] = ans;
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
    memset(a, -1, sizeof(a));
    cin >> n >> k;
    f(1, n + 1)
            fi(1, n + 1)
                cin >>
        w[i][j];
    cout << rec(1, k, 0);
}