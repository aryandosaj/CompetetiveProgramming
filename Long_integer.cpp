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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x;
    cin >> x;
    stack<ll> dig;
    ll r = 0;
    f(0, x.length())
        r = (r * 10 + (x[i] - '0')) % MOD,
        dig.push(x[i] - '0');
    ll q;
    cin >> q;

    while (q--)
    {
        char c;
        ll d;
        cin >> c;
        if (c == '+')
        {
            ll d;
            cin >> d;
            dig.push(d);
            r = (r * 10 + d) % MOD;
            cout << r << "\n";
        }
        else
        {
            ll d = dig.top();
            dig.pop();
            r = (((r - d + MOD) % MOD) * invmod(10, MOD)) % MOD;
            cout << r << "\n";
        }
    }
}