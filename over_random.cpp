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
        cout << "Case #" << k << ": ";
        ll u;
        cin >> u;
        set<string> s;
        map<ll, vector<string>> mp;
        ll q = 10000;
        f(0, q)
        {
            string r;
            ll num;
            cin >> num >> r;
            mp[num].pb(r);
            for (auto j : r)
            {
                string r="";
                r.pb(j);
                s.insert(r);
            }
        }
        map<string, ll> vis;
        map<ll, string> dig;
        f(1, 10)
        {
            for (auto j : mp[i])
            {
                if (vis[j] == 0)
                {
                    vis[j] = 1;
                    dig[i] = j;
                    break;
                }
            }
        }
        for (auto i : s)
        {
            if (vis[i] == 0)
            {
                dig[0] = i;
                break;
            }
        }
        for (auto i : dig)
            cout << i.second;
        cout << "\n";
    }
}