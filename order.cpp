#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ld long double
#define pl pair<ll, ll>
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
ll arr[200005];
ll ans[200005];
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
        ordered_set st;
        ll n;
        cin >> n;
        f(1, n + 1)
                cin >>
            arr[i],
            st.insert(i);
        for (int i = n; i > 0; i--)
        {
            auto p = st.find_by_order(i - arr[i] - 1);
            ll ind = *p;
            st.erase(p);
            ans[i] = ind;
        }
        f(1, n + 1)
                cout
            << ans[i] << " ";
        cout << "\n";
    }
}