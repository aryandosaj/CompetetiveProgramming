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
ll b[200005];
vll v;
ll n, m;
ll x, y, k;
ll flag;
ll rec(vll arr, ll xx, ll yy)
{
    // for (auto i : arr)
    //     cout << i << " ";
    // cout << "\n";
    ll siz = arr.size();
    ll mx = 0;
    for (auto i : arr)
        mx = max(mx, i);
    ll ans = 0;
    if (siz < k && mx > xx && mx > yy)
    {
        flag = 1;
        return 0;
    }
    ll g = max(xx, yy);
    if (x > y * k)
    {
        ll c = 0;
        for (auto i : arr)
            if (g < i)
                c++;
        if (c)
            ans += (siz - k) * y,
                ans += x;
        else
            ans += siz * y;
    }
    else
    {
        if (siz % k != 0)
            ans += y * (siz % k),
                siz -= (siz % k);
        ans += (siz / k) * x;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin >> x >> k >> y;
    f(0, n) cin >> a[i];
    ll ind = 0;
    ll l = -1, r = -1;
    ll ans = 0;
    ll c = 0;
    f(0, m)
    {
        cin >> b[i];
        swap(l, r);
        r = b[i];
        // cout << ans << "\n";
        while (ind < n)
        {

            if (b[i] == a[ind])
            {
                ans += rec(v, l, r);
                v.clear();
                ind++;
                c++;
                break;
            }
            v.pb(a[ind]);
            ind++;
        }
    }
    f(ind, n)
        v.pb(a[i]);
    ans += rec(v, r, -1);
    if (flag || c < m)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
}
