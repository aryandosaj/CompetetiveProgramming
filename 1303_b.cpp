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
    {
        ll n, g, b;
        cin >> n >> g >> b;
        ll req = n / 2 + (n & 1);
        ll days = 0;

        if (req <= g)
        {
            cout << n << "\n";
            continue;
        }
        req -= g;
        days += g;

        if (req == 0)
        {
        }
        else
        {
            ll x = b + g;
            ll d = req / g;
            ll bad = d * b;
            days += x * d;
            if (req % g)
            {
                days += b + (req % g);
                bad += b;
            }
            ll left = n / 2;
            if (left <= bad)
                cout << days << "\n";
            else
            {
                cout << days + left - bad << "\n";
            }
        }
    }
}