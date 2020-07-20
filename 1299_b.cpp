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
ll dist(pl a, pl b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
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
    pll v;
    f(0, n)
    {
        ll x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    v.pb(v[0]);
    if (n & 1)
        cout << "No\n";
    else
    {
        f(0, n / 2)
        {
            // cout << ((v[i].second - v[i + 1].second) * (v[n / 2 + i].first - v[n / 2 + i + 1].first)) << " ";
            // cout << ((v[i].first - v[i + 1].first) * (v[n / 2 + i].second - v[n / 2 + i + 1].second)) << "\n";
            if ((((v[i].second - v[i + 1].second) * (v[n / 2 + i].first - v[n / 2 + i + 1].first)) != ((v[i].first - v[i + 1].first) * (v[n / 2 + i].second - v[n / 2 + i + 1].second))) || (dist(v[i], v[i + 1]) != dist(v[n / 2 + i], v[n / 2 + i + 1])))
            {
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
    }
}