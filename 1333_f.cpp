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
const int N = 1000000;
int lp[N + 1];
ll vis[N];
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
    vector<int> pr;
    for (int i = 2; i <= n; ++i)
    {
        if (lp[i] == 0)
            lp[i] = i,
            pr.push_back(i);
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
            lp[i * pr[j]] = pr[j];
    }
    vll ans;
    for (auto i : pr)
        ans.pb(1);
    ll cur_gcd = 1;

    f(pr.size(), n + 1)
    {
        cur_gcd++;
        ll f = 0;
        for (ll j = 0; pr[j] <= lp[cur_gcd] && i <= n && pr[j] * cur_gcd <= n; j++, i++)
            if (vis[pr[j] * cur_gcd] == 0)
                ans.pb(cur_gcd), f = 1, pr.pb(pr[j] * cur_gcd), vis[pr[j] * cur_gcd] = 1;
            else
                i--;
        if (f)
            i--;
    }
    f(0, ans.size()) cout << ans[i] << " ";
    cout << "\n";
    // f(0, pr.size()) cout << pr[i] << "\t";
    // cout << "\n";
    // f(0, pr.size()) cout << i + 2 << "\t";
}