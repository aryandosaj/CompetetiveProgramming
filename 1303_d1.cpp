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
map<ll, ll> pre;
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
        vll v;
        ll x = 1;
        while (x <= 1e18)
        {
            v.pb(x);
            x *= 2;
        }
        ll sum = 0;

        for (auto i : v)
        {
            pre[i] = sum;
            sum += mp[i] * i;
        }
        reverse(v.begin(), v.end());
        ll c = 0;
        ll flag = 0;
        for (auto i : v)
        {

            if (i & n)
            {
                if (mp[i])
                {
                    mp[i]--;
                    n -= i;
                    c += mp[i];
                }
                else
                {
                    if (pre[i] - n >= i)
                    {
                    }
                    else
                    {
                        if (c > 0)
                        {
                            c--;
                            n -= i;
                        }
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}