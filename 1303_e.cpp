#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
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
string s, t;
ll dp[401][401][401];
ll rec(ll i, ll j, ll k)
{
    if (s.length() == i)
    {
        if (t.length() == k)
            return j;
        return -1e9;
    }
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    ll ans = rec(i + 1, j, k);
    if (j < t.length() && s[i] == t[j])
        ans = max(ans, rec(i + 1, j + 1, k));

    if (k < t.length() && s[i] == t[k])
        ans = max(ans, rec(i + 1, j, k + 1));
    return dp[i][j][k] = ans;
}
void solve()
{
    cin >> s >> t;
    ll n = s.length()+1;
    f(0, n) fi(0, t.length()+1) fii(0, t.length()+1) dp[i][j][k] = -1;
    f(0, t.length()+1)
    {
        if (rec(0, 0, i) >= i)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
}