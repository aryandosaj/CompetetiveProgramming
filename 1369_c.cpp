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
ll a[200005];
ll w[200005];
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
        f(0, n) cin >> a[i];
        f(0, k) cin >> w[i];
        sort(a, a + n);
        sort(w, w + k, greater<ll>());
        ll ans = 0;
        ll last = 0;
        ll st = n - 1;
        ll ind=k-1;
        while (w[ind]==1)
        {
            ans+=2*a[st];
            st--;
            ind--;
        }
        
        f(0, ind+1)
        {
            // cout<<ans<<"\n";
            ans += a[st];
            if (w[i] > 1)
                ans += a[last];
            else
                ans += a[st];
            st--;
            last += w[i] - 1;
        }
        cout << ans << "\n";
    }
}