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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        set<ll> s;
        f(0, n)
        {
            cin >> arr[i];
            if (i != arr[i])
                s.insert(i);
        }
        vll ans;
        ll mex;
        while (!s.empty())
        {
            ll i = *s.begin();
            ll vis[n + 1];
            fi(0, n + 1) vis[j] = 0;
            fi(0, n) vis[arr[j]] = 1;
            fi(0, n+1)
            {
                if (vis[j] == 0)
                {
                    mex = j;
                    break;
                }
            }
            if (mex == n)
            {
                ans.pb(i + 1);
                mex = arr[i];
                arr[i] = n;
            }
            arr[mex] = mex;
            ans.pb(mex+1);
            s.erase(mex);
        }
        // for (int i = 0; i < n; i++)
        //     cout << arr[i] << " ";
        // cout << "\n";
        // return 0;

        cout << ans.size() << "\n";
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}
