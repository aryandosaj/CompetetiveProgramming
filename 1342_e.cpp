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
ll fact[200005];
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
ll invmod(ll x, ll m)
{
    return power(x, m - 2, m);
}
ll ncr(ll n, ll r)
{
    return (((fact[n] * invmod(fact[r], MOD)) % MOD) * invmod(fact[n - r], MOD)) % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    f(1, 200005) fact[i] = (fact[i - 1] * i) % MOD;
    ll n, k;
    cin >> n >> k;
    if (k > n - 1)
    {
        cout << "0\n";
        return 0;
    }
    ll d = (n - k);
    ll ans = 0;
    f(0, d + 1)
    {
        if (i & 1)
            ans = (ans - ((ncr(d, i) * power((d - i), n, MOD)) % MOD) + 2 * MOD) % MOD;
        else
            ans = (ans + ((ncr(d, i) * power((d - i), n, MOD)) % MOD) + 2 * MOD) % MOD;
        // cout << ans << "\n";
    }
    ans = (ans * ncr(n, d)) % MOD;
    // ans = (ans * invmod(fact[d], MOD)) % MOD;
    if(k)
    cout << (ans * 2) % MOD << "\n";
    else cout<<ans;
}