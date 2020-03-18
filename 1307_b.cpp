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
        map<ll, ll> mp;
        ll n, x;
        cin >> n >> x;
        f(0, n) cin >> arr[i], mp[arr[i]] = 1;
        sort(arr, arr + n, greater<ll>());
        if (mp[x])
        {
            cout << "1\n";
            continue;
        }
        if (x < arr[0])
        {
            cout << "2\n";
            continue;
        }
        ll ans = x / arr[0];
        if (x % arr[0])
            ans++;
        cout << ans << "\n";
    }
}