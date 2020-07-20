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
ll arr[200005];
ll brr[200005];
set<ll> adj[200005];
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
        cin >> n;
        f(0, n+1) adj[i].clear();
        f(0, n)
        {
            cin >>
                arr[i],
                brr[i] = (i + arr[i] + n * MOD) % n;
            adj[brr[i]].insert(i);
        }
        // f(0, n) cout << brr[i] << " ";
        ll f = 0;
        f(0, n)
        {
            if (adj[i].size() > 1)
            {
                f = 1;
                break;
            }
        }
        if (f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}