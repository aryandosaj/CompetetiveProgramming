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

    fii(1, t + 1)
    {
        pll v;
        vll l[1500];
        vll r[1500];
        ll n;
        cin >> n;
        char ans[n];
        f(0, n)
        {
            ans[i] = 'x';
            ll s, e;
            cin >> s >> e;
            l[s].pb(i);
            r[e].pb(i);
        }
        set<ll> s;
        ll f = 0;
        ll p = 1;
        f(0, 1500)
        {
            for (auto j : r[i])
                s.erase(j);
            ll last = -1;
            if (s.size())
                last = ans[*s.begin()];
            for (auto j : l[i])
                s.insert(j);

            if (s.size() > 2)
            {
                f = 1;
                break;
            }
            if (last != -1)
                for (auto j : l[i])
                    ans[j] = 1 - last;
            else
                for (auto j : l[i])
                    ans[j] = p, p = 1 - p;
        }
        if (f)
            cout << "Case #" << k << ": IMPOSSIBLE\n";
        else
        {
            cout << "Case #" << k << ": ";
            f(0, n)
            {
                if (ans[i])
                    cout << 'C';
                else
                    cout << 'J';
            }
            cout << "\n";
        }
    }
}