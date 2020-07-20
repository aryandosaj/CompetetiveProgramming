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
string adj[200005];
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
        string s;
        cin >> s;
        string temp = "";
        f(1, n + 1)
        {
            temp.pb(s[i - 1]);
            if (i % k == 0)
                adj[i / k] = temp,
                        temp = "";
        }
        ll ans = 0;
        f(0, k / 2)
        {
            ll mc = MOD;
            for (char c = 'a'; c <= 'z'; c++)
            {
                ll cost = 0;
                fi(1, n / k + 1)
                {
                    if (adj[j][i] != c)
                        cost++;
                    if (adj[j][k - i - 1] != c)
                        cost++;
                }
                mc = min(mc, cost);
            }
            ans += mc;
        }
        if (k % 2)
        {
            ll mc = MOD;
            for (char c = 'a'; c <= 'z'; c++)
            {
                ll cost = 0;
                fi(1, n / k + 1) if (adj[j][k / 2] != c)
                    cost++;
                mc = min(mc, cost);
            }
            ans += mc;
        }
        cout<<ans<<"\n";
    }
}
