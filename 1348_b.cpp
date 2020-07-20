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
        ll n, k;
        cin >> n >> k;
        vll a;
        set<ll> s;
        f(0, n)
        {
            ll x;
            cin >> x;
            a.pb(x);
            s.insert(x);
        }
        if (s.size() > k)
        {
            cout << "-1\n";
            continue;
        }
        else
        {
            ll ind = 1;
            while ((ll)s.size() < k)
            {
                s.insert(ind++);
            }
            vll ans;
            f(0, a.size())
            {
                for (auto j : s)
                {
                    ans.pb(j);
                }
            }
            cout << ans.size() << "\n";
            for (auto i : ans)
                cout << i << " ";
            cout << "\n";
        }
    }
}