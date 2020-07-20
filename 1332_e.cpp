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
long long power(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll range = (r - l + 1);

    ll ne = range / 2;
    ll no = range / 2;
    n = n * m;
    if (range & 1)
    {
        if (l & 1)
            no++;
        else
            ne++;
    }
    ll ans = ((power(2, MOD - 2, MOD) * (power(no + ne, n, MOD) + power(no - ne, n, MOD)+MOD)) % MOD) % MOD;
    if (n & 1)
        ans = power(no + ne, n, MOD);
    cout << ans;
}