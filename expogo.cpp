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
    ll g = 0;
    while (t--)
    {
        g++;
        cout << "Case #" << g << ": ";
        ll a, b;
        cin >> a >> b;
        ll sum = abs(a) + abs(b);
        ll c = 0;
        ll x = 1;
        while (x <= sum)
            x *= 2;
        vll v1;
        vll v2;
        ll aa = abs(a);
        ll bb = abs(b);
        x /= 2;
        while (x)
        {
            if (sum > 0)
            {
                if (aa > bb)
                    v1.pb(x), aa -= x;
                else
                    v2.pb(x), bb -= x;
                sum -= x;
            }
            else
            {
                if (aa > bb)
                    v1.pb(-x), aa -= x;
                else
                    v2.pb(-x), bb -= x;
                sum += x;
            }
            x /= 2;
            aa = abs(aa);
            bb = abs(bb);
        }
        if (sum != 0)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        // for (auto i : v1)
        //     cout << i << " ";

        vector<char> a1;
        map<ll, char> mp;
        f(0, v1.size())
        {
            if (a > 0)
            {
                if (v1[i] > 0)
                    mp[abs(v1[i])] = 'E';
                else
                    mp[abs(v1[i])] = 'W';
            }
            else
            {
                if (v1[i] > 0)
                    mp[abs(v1[i])] = 'W';
                else
                    mp[abs(v1[i])] = 'E';
            }
        }

        f(0, v2.size())
        {
            if (b > 0)
            {
                if (v2[i] > 0)
                    mp[abs(v2[i])] = 'N';
                else
                    mp[abs(v2[i])] = 'S';
            }
            else
            {
                if (v2[i] > 0)
                    mp[abs(v2[i])] = 'S';
                else
                    mp[abs(v2[i])] = 'N';
            }
        }

        ll x1 = 0, y1 = 0;
        for (auto i : mp)
        {
            cout << i.second;
            if (i.second == 'N')
                y1 += i.first;
            if (i.second == 'S')
                y1 -= i.first;
            if (i.second == 'E')
                x1 += i.first;
            if (i.second == 'W')
                x1 -= i.first;
        }
        // cout<<x1<<" "<<y1<<" "<<a<<" "<<b;
        cout << "\n";
    }
}