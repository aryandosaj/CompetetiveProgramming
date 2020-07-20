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
map<ll, ll> p_fac;
vll p;
unordered_map<ll, vll> adj;
ll fac[100];
void factorize(long long n)
{
    int count = 0;
    while (!(n % 2))
    {
        n >>= 1;
        count++;
    }
    if (count)
        p_fac[2] = count, p.pb(2);
    for (long long i = 3; i <= sqrt(n); i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
        if (count)
            p_fac[i] = count, p.pb(i);
    }
    if (n > 2)
        p_fac[n] = 1, p.pb(n);
}
ll power(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll calc(ll n, vll v)
{
    ll ans = fac[n];
    for (auto i : v)
        ans = (ans * power(fac[i], MOD - 2, MOD)) % MOD;
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = 1;
    f(1, 100) fac[i] = (fac[i - 1] * i) % MOD;
    ll d;
    cin >> d;
    factorize(d);
    ll q;
    cin >> q;
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        if (u < v)
            swap(u, v);

        vll rid, req;
        ll re = 0, ri = 0;
        for (auto i : p)
        {
            ll c1 = 0;
            while (u % i == 0)
                u /= i, c1++;

            ll c2 = 0;
            while (v % i == 0)
                v /= i, c2++;
            if (c1 == c2)
                continue;
            if (c1 < c2)
                req.pb(c2 - c1), re += (c2 - c1);
            else
                rid.pb(c1 - c2), ri += (c1 - c2);
        }
        ll ans = (calc(re, req) * calc(ri, rid)) % MOD;

        cout << ans << "\n";
    }
}