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
        ll n, k;
        string s;
        cin >> n >> k >> s;
        map<char, ll> mp;
        f(0, s.length())
            mp[s[i]]++;
        string ans = "";
        ll f = 0;
        char c = (*mp.begin()).first;
        if (mp[c] < k)
        {
            ll c = 0;
            for (auto i : mp)
            {
                c += i.second;
                if (c >= k)
                {
                    ans.pb(i.first);
                    cout << ans << "\n";
                    f = 1;
                    break;
                }
            }
        }
        if (f)
            continue;
        ans.pb(c);
        mp[c] -= k;
        if (n == k)
        {
            cout << ans << "\n";
            continue;
        }
        if (mp[c] == 0)
            c = ((*mp.upper_bound(c)).first);
        if (mp.upper_bound(c) != mp.end())
        {
            for (auto i : mp)
                fi(0, i.second) ans.pb(i.first);
            cout << ans << "\n";
        }
        else
        {
            f(0, (mp[c]) / k)
                ans.pb(c);
            if (mp[c] % k)
                ans.pb(c);
            cout << ans << "\n";
        }
        continue;

        
    }
}