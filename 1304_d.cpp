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
        ll n;
        string s;
        cin >> n >> s;
        ll f = 0;
        ll c = 0;
        vll v;
        if (s[0] == '>')
            f = 1;
        ll g = 0;
        ll l = 0;
        f(0, n - 1)
        {

            if (s[i] == '<')
            {
                l++;
                if (f == 0)
                    c++;
                else
                    v.pb(c), c = 1, f = 0;
            }
            else
            {
                g++;
                if (f == 1)
                    c++;
                else
                    v.pb(c), c = 1, f = 1;
            }
        }

        v.pb(c);
        f = 0;
        v[0]++;
        if (s[0] == '>')
            f = 1, g++;
        else
            l++;
        vll a;
        vll b;
        // g = n-g;
        // ll gg = g;ṇ
        // cout << l << " " << g << "\n";
        ll x = g + 1;
        l = n;

        for (auto i : v)
        {
            // cout << i << "\n";
            if (f)
            {
                fi(1, i + 1)
                    a.pb(g),
                    b.pb(g--);
                f = 0;
            }
            else
            {
                fi(1, i + 1)
                    a.pb(l - i + j),
                    b.pb(x++);
                l -= i;
                f = 1;
            }
        }
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
        for (auto i : b)
            cout << i << " ";
        cout << "\n";
    }
}