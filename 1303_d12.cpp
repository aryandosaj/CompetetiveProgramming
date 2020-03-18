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
        multiset<ll, greater<ll>> s;
        ll n, m, sum = 0;
        cin >> n >> m;
        f(0, m) cin >> arr[i], s.insert(arr[i]), sum += arr[i];
        ll ans = 0;
        while (s.size())
        {
            ll f = *s.begin();
            s.erase(s.begin());
            if (sum - f >= n)
                sum -= f;
            else if (n < f)
                s.insert(f / 2),
                    s.insert(f / 2),ans++;
            else
                n -= f,sum-=f;
        }
        if (n)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
}