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
ll food[100005];
vll adj[200005];
pl frnd[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    f(1, n + 1)
            cin >>
        food[i];
    f(1, m + 1)
    {
        ll u, v;
        cin >> u >> v;
        frnd[i] = {u, v};
        adj[u].pb(i);
        adj[v].pb(i);
    }
    map<ll, ll> mp;
    set<pl, greater<pl>> s;
    ll flag = 0;
    f(1, n + 1)
    {
        mp[i] = food[i] - adj[i].size(),
        s.insert({mp[i], i});
    }
    vll ans;
    map<ll, ll> vis;
    map<ll, ll> vis1;
    ll t;
    t = 10;
    while (!s.empty())
    {
        pl u = *s.begin();
        ll f = u.second;
        if (u.first < 0)
        {
            cout << "DEAD\n";
            return 0;
        }
        s.erase(s.begin());
        if (vis[f] == 1)
            continue;
        vis[f] = 1;
        for (auto i : adj[f])
        {
            if (vis1[i] == 0)
                ans.pb(i), vis1[i] = 1;
            // if (vis[i] == 1)
            //     continue;
            if (frnd[i].first != f)
            {
                s.erase({mp[frnd[i].first], frnd[i].first});
                mp[frnd[i].first]++;
                s.insert({mp[frnd[i].first], frnd[i].first});
            }
            else
            {
                s.erase({mp[frnd[i].second], frnd[i].second});
                mp[frnd[i].second]++;
                s.insert({mp[frnd[i].second], frnd[i].second});
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "ALIVE\n";
    for (auto i : ans)
        cout << i << " ";
}