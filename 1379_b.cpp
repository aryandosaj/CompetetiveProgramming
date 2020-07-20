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
        ll l, r, m;
        cin >> l >> r >> m;
        ll a = -1, b=-1, c=-1;
        ll rem = (r - l);
        ll n;

        if (m >= (l - rem) && m <= r + rem)
        {
            if (m >= r)
            {
                a = r;
                n = 1;
                b = l + m - r;
                c = l;
            }
            else if (m >= r - rem)
            {
                a = r;
                b = l;
                c = l + (r - m);
            }
            else if (m >= l)
            {
                a = m;
                b = l;
                c = l;
            }
            else if (m >= l - rem)
            {
                a = l;
                b = l;
                c = l + (l - m);
            }
        }
        else
        {
            f(l, r + 1)
            {
                if ((m % i) <= rem)
                {
                    n = m / i;
                    a = i;
                    b = m % i + l;
                    c = l;
                    break;
                }
                else if (i - (m % i) <= rem)
                {
                    n = m / i + 1;
                    a = i;
                    c = l + (i - m % i);
                    b = l;
                }
            }
        }
        cout << a << " " << b << " " << c << "\n";

        // cout << n << " " << n * a + b - c << "\n";
    }
}