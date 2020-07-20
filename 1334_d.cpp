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
    ll t;
    cin >> t;
    while (t--)
    {
        vll ans;
        ll n, l, r;
        cin >> n >> l >> r;
        vll v;
        v.pb(MOD);
        ll x = 1;
        ll st = 1, en = 0, sn = 1, e_n = 0;
        if (l == 1)
        {
            ans.pb(1);
        }
        else
        {

            f(1, n + 1)
            {
                sn = x;
                x += 2 * (n - i);
                if (x >= l)
                {
                    st = i;
                    break;
                }
            }
        }
        x = 1;
        f(1, n + 1)
        {
            e_n = x;
            x += 2 * (n - i);
            if (x >= r)
            {
                en = i;
                break;
            }
        }
        x = sn;
        f(st, en + 1)
        {
            ll c = 0;
            fi(0, 2 * (n - i))
            {
                x++;
                ll num;
                if (j & 1)
                {
                    if (j < 2 * (n - i) - 1)
                        num = i;
                    else
                        num = i + 1;
                    if (i == n - 1)
                        num = 1;
                }
                else
                {
                    c++;
                    num = i + c;
                }
                if (x >= l && x <= r)
                    ans.pb(num);
                if (x > r)
                    break;
                // cout << num << "-" << x << "\n";
            }
            // cout << "\n";
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}