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
    ll n, m;
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    ll t[n + 1][m + 1];
    ll f[n + 1][m + 1];
    ll vis[n + 1][m + 1];
    f(0, n) fi(0, m)
            cin >>
        t[i][j],
        vis[i][j] = 0;
    f(0, n) fi(0, m)
            cin >>
        f[i][j];
    unordered_map<ll, map<ll, ll>> mp;
    queue<pl> q;
    q.push({n - 1, m - 1});
    vis[n - 1][m - 1] = 1;
    mp[0][0] = t[n - 1][m - 1];
    ll ans = -1;
    for (ll i = n - 1; i >= 0; i--)
        for (ll j = m - 1; j >= 0; j--)
        // f(0,n)fi(0,m)
        {
            pl u;
            u.first = i;
            u.second = j;
            ll d = (n - 1 - u.first);
            ll d2 = m - 1 - u.second;
            ll val = 1e15, m;
            for (int k = i; k < n; k++)
            {
                ll x = (k + d2 - i - j) * f[u.first][u.second] + mp[k][k + d2] + t[u.first][u.second];
                if (val > x)
                {
                    val = x;
                    m = i;
                }
            }
            
        }
    cout << ans << "\n";
}