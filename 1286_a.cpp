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
ll vis[110];
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
    ll a[n];
    ll od = 0, ev = 0;
    f(0, n)
    {
        cin >>
            a[i];
        vis[a[i]] = 1;
        if (a[i] & 1)
            od++;
        else
            ev++;
    }

    ll c = 0;
    ll last = -1;
    ll o = 0, e = 0, o1 = 0, e1 = 0;
    ll oe = 0;
    f(0, n)
    {
        if (a[i] == 0)
            c++;
        else if (c)
        {
            if (last == -1)
            {
                if (a[i] & 1)
                    o1 += 1;
                else
                    e1 += 1;
            }
            else
            {
                if ((last ^ a[i]) & 1)
                    oe += 1;
                else if (last & 1)
                    o += 1;
                else
                    e += 1;
            }
            c = 0;
            last = a[i];
        }
    }
    if (c)
    {
        if (last & 1)
            o1 += 1;
        else
            e1 += 1;
    }
    ll ans = 0;

    f(1, n + 1) cout << vis[i] << " " << i << "\n";
    f(0, n - 1) if (a[i] != 0 && a[i + 1] != 0)
        ans += ((a[i] ^ a[i + 1]) & 1);
    cout << ans + 2 * o + 2 * e + e1 + o1 + oe;
}