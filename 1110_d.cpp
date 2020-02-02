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
ll n, m;
// ll arr[1000001];

unordered_map<ll, ll> mp;
ll dp[1000001][3][3];
ll rec(ll i, ll f, ll s)
{
    // cout<<i<<"\n";
    if (i == m + 1)
        return 0;
    if (dp[i][f][s] != -1)
        return dp[i][f][s];
    ll nn = mp[i];
    nn -= f;
    nn -= s;
    if (nn < 0)
        return -MAX;
    ll c = min(nn + 1, (ll)3);
    ll temp = -MAX;
    for (ll j = 0; j < c; j++)
        temp = max(temp, ((nn - j) / 3) + f + rec(i + 1, s, j));
    return dp[i][f][s] = temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < 1000001; i++)
        for (ll j = 0; j < 3; j++)
            for (ll k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    cout << rec(0, 0, 0);
}