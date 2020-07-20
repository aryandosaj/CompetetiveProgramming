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
    ll n, k;
    cin >> n >> k;
    vll a, b, ab;
    f(0, n)
    {
        ll x, y, t;
        cin >> t >> x >> y;
        if (x && y)
            ab.pb(t);
        else if (x)
            a.pb(t);
        else if(y)
            b.pb(t);
    }
    ll aa = 0, bb = 0;
    ll ans = 0;
    sort(ab.begin(), ab.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (ab.size() + a.size() < k || ab.size() + b.size() < k)
    {
        cout << "-1";
        return 0;
    }
    ll ia = 0, ib = 0, iab = 0;
    f(0,k)
    {
        ll p = MOD;
        ll q = MOD;
        ll r = MOD;
        if (a.size() > ia)
            p = a[ia];
        if (b.size() > ib)
            q = b[ib];
        if (ab.size() > iab)
            r = ab[iab];
        if (r < p + q)
        {
            iab++;
            ans += r;
        }
        else
        {
            ia++;
            ib++;
            ans += p + q;
        }
    }
    cout<<ans;
}