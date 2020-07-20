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
ll ans[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "10";
        return 0;
    }
    if (n == 2)
    {
        cout << "180 10";
        return 0;
    }
    f(1, n + 1)
    {

        if (i == n - 1)
        {
            cout << "180 ";
        }
        else if (i == n)
        {
            cout << "10";
        }
        else
        {
            ll a = (2 * 10 * 9 * power(10, n - i - 1, MOD)) % MOD;
            ll b = ((((n - i - 1) * 10 * 9 * 9) % MOD) * power(10, n - i - 2, MOD)) % MOD;
            // cout<<a<<" "<<b<<"\n";
            cout << (a + b) % MOD << " ";
        }
    }
}