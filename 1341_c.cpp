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
ll p[100005];
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
        f(1, n + 1)
        {
            ll x;
            cin >> x;
            p[x] = i;
        }
        map<ll, ll> vis;
        ll f = 0;

        f(1, n + 1)
        {
            // cout << i << " " << p[i] << "\n";

            ll pos = p[i];
            ll num = i;
            if (vis[pos] == 1)
            {
                f = 1;
                break;
            }
            vis[pos] = 1;
            pos++;
            num++;
            while (pos <= n)
            {
                if (vis[pos] == 0)
                {
                    vis[pos] = 1;
                    if (p[num] != pos)
                    {
                        f = 1;
                        break;
                    }
                }
                else
                {
                    i = num - 1;
                    break;
                }
                i = num;
                num++;
                pos++;
            }

            if (f)
                break;
        }

        if (f)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}