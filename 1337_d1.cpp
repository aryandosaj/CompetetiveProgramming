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
// ll a[100005];
// ll b[100005];
// ll c[100005];
unordered_map<ll, ll> a, b, c;
vll v;
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
        a.clear();
        b.clear();
        c.clear();
        v.clear();
        ll rrr, g, bl;
        cin >> rrr >> g >> bl;
        ll x;
        f(0, rrr) cin >> x, a[x] = 1, v.pb(x);
        f(0, g) cin >> x, b[x] = 1, v.pb(x);
        f(0, bl) cin >> x, c[x] = 1, v.pb(x);
        sort(v.begin(), v.end());
        ll rr = MOD, gg = MOD, bb = MOD;
        ll ans = 4e18;
        ll l = 0, r = 0;
        ll f = 0;
        while (l < v.size())
        {
            if (rr != MOD && bb != MOD && gg != MOD && f == 0)
            {
                while (l < r)
                {
                    ans = min(ans, (rr - bb) * (rr - bb) + (rr - gg) * (rr - gg) + (gg - bb) * (gg - bb));
                    l++;
                    if (l == v.size())
                        break;
                    if (a[v[l]])
                        rr = v[l];
                    if (b[v[l]])
                        gg = v[l];
                    if (c[v[l]])
                        bb = v[l];
                }
                if (l == v.size())
                    break;
                if (a[v[l-1]])
                    rr = MOD;
                if (b[v[l-1]])
                    gg = MOD;
                if (c[v[l-1]])
                    bb = MOD;
                f = 1;
            }
            else
            {
                if (r >= v.size())
                    break;

                if (rr == MOD && a[v[r]])
                    rr = v[r];
                if (gg == MOD && b[v[r]])
                    gg = v[r];
                if (bb == MOD && c[v[r]])
                    bb = v[r];
                r++;
                f = 0;
            }
        }
        cout << ans << "\n";
    }
}