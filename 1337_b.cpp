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
        ll n, m, x;
        cin >> x >> n >> m;
        ll to = n + m;
        f(0, to)
        {
            if (x <= 0)
                break;
            if (n > 0 && m > 0)
            {
                if ((x / 2 + 10) < x )
                {
                    n--;
                    x = x / 2 + 10;
                }
                else
                {
                    x -= 10;
                    m--;
                }
            }
            else 
            if (n)
            {
                n--;
                x = x / 2 + 10;
            }
            else
            {
                x -= 10;
                m--;
            }
        }
        if (x > 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}