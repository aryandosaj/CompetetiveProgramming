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
ll fact[100005];
ll dp[53][50001];
unordered_map<char,ll>dp2;
vector<char> v;
unordered_map<ll, ll> mp;

ll inv(ll t)
{
    return power(t, MAX - 2, MAX);
}
ll fun(ll n, ll k)
{
    if (dp[n][k] != -1)
        return dp[n][k];
    if (k == 0)
        return 1;
    if (n >= v.size())
        return 0;

    if (k > 0)
    {
        ll temp = fun(n + 1, k - mp[v[n]]);
        dp2[v[n]] += temp;
        return dp[n][k] = fun(n + 1, k) + (mp[v[n]] > 0 ? temp : 0);
    }
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    string s;
    cin >> s;
    n = s.length();
    fact[0] = 1;
    for (ll i = 1; i < 100005; i++)
        fact[i] = (fact[i - 1] * i) % MAX;
    for (ll i = 0; i < s.length(); i++)
        mp[s[i]]++;
    for (ll i = 0; i < 53; i++)
        for (ll j = 0; j < 50001; j++)
            dp[i][j] = -1;
    ll t = 1;
    for (auto i : mp)
        (t *= fact[i.second]) %= MAX, v.push_back(i.first);
    ll u = fun(0, n / 2);
    cout << u << " "<<dp2['a']<<" "<<dp2['b']<<" ";
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        ll ans = (u - dp2[s[x]] - dp2[s[y]] + MAX + MAX) % MAX;
        (ans *= ((fact[n / 2] * fact[n / 2] * 2) % MAX) * inv(t)) %= MAX;
        cout << ans << "\n";
    }
}