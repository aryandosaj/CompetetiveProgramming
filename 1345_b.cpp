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
    ll np[100005];
    ll h = 1;
    np[1] = 2;
    ll x = 2;
    while (x + 2 + 3 * h < 3000000009)
    {
        x = x + 2 + 3 * h;
        h++;
        np[h] = x;
    }
    
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll c = 0;
        while (n > 1)
        {
            auto x = upper_bound(np, np + h + 1, n);
            if (x == np)
                break;
            x--;
            n -= (*x);
            c++;
        }
        cout << c << "\n";
    }
}