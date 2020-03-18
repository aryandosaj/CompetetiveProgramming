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
ll arr[100005];
map<ll, ll> mp;
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
        mp.clear();
        ll n, m, sum = 0;
        cin >> n >> m;
        f(0, m)
                cin >>
            arr[i],
            mp[arr[i]]++, sum += arr[i];
        if (sum < n)
        {
            cout << "-1\n";
            continue;
        }
        ll req = sum - n;
        vll v;
        ll x = 1;
        while (x <= 1e18)
        {
            v.pb(x);
            x *= 2;
        }
        ll ans = 0;
        reverse(v.begin(), v.end());
        for (auto i : v)
        {
            if (req == 0)
                break;
            if(req>=i)
            {
                ll k = i;
                ll f = mp[i];
                if (f)
                {
                    ll r = req / k;
                    if (r >= f)
                    {
                        mp[i] -= f;
                        req -= f * k;
                    }
                    else
                    {
                        mp[i] -= r;
                        req -= r * k;
                    }
                }
            }
        }
        for(auto i:v)
        {
            if(i==1)break;
            {
                ll k = i / 2;
                ll f = mp[i];
                if (f)
                {
                    ll r = req / k;
                    if (r >= f)
                    {
                        mp[i] -= f;
                        mp[k] += f;
                        req -= f * k;
                        ans += f;
                    }
                    else
                    {
                        mp[i] -= r;
                        mp[k] += r;
                        req -= r * k;
                        ans += r;
                    }
                }
            }
        }
        if (req == 0)
            cout << ans << "\n";
        else
            cout << "-1\n";
    }
}