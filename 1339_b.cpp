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
ll arr[100005];
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
        f(0, n) cin >> arr[i];
        sort(arr, arr + n);
        ll ind = n / 2;
        vll v;
        vll v1;
        f(0, n / 2) v.pb(arr[i]);
        f(n / 2, n) v1.pb(arr[i]);
        reverse(v.begin(), v.end());
        vll ans;
        ll f = 0;
        f(0, n)
        {
            if (i & 1)
                ans.pb(v[i / 2]);
            else
                ans.pb(v1[i / 2]);
        }
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}