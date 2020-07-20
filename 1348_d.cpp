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
        ll n;
        cin >> n;
        ll x = 1;
        ll d = 0;
        ll a = 2;
        vll ans;
        map<ll, ll> mp;
        while (x + a < n)
        {
            ans.pb(a / 2);
            d++;
            x += a;
            a *= 2;
        }
        ll rem = n - x;
        if (rem == 0)
        {
            cout << d << "\n";
            for (auto i : ans)
                cout << i << " ";
            cout << "\n";
            continue;
        }
        a /= 2;
        if (rem >= a)
        {
            ans.pb(rem - a);
            cout << d + 1 << "\n";
            for (auto i : ans)
                cout << i << " ";
            cout << "\n";
        }
        else
        {
            ll f = 1;
            while (f <= rem)
                f *= 2;
            f /= 2;
            mp[f] = rem - f;
            cout << d + 1 << "\n";
            for (auto i : ans)
            {
                if (mp.find(i) != mp.end())
                    cout << mp[i] << " " << i - mp[i] << " ";
                else
                    cout << i << " ";
            }
            cout << "\n";
        }
    }
}