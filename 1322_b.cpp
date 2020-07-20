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
ll arr[10004];
ll col[1003];
ll a[1003];
ll vis[1003];
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
        f(0, 1003) col[i] = 0, vis[i] = 0;
        set<ll> s;
        ll n;
        cin >> n;
        f(0, n)
                cin >>
            arr[i],
            a[arr[i]]++, s.insert(arr[i]);

        map<ll, set<ll>> mp;
        for (auto j : s)
        {
            ll num = j;
            if (num % 2 == 0)
            {
                mp[2].insert(j);
                while (num % 2 == 0)
                    num /= 2;
            }
            for (int i = 3; i <= sqrt(num); i = i + 2)
            {
                while (num % i == 0)
                {
                    mp[i].insert(j);
                    num = num / i;
                }
            }

            if (num > 2)
                mp[num].insert(j);
        }
        ll c = 1;
        ll f = 0;
        for (auto i : mp)
        {
            if (f)
                c++;
            f = 0;
            for (auto j : i.second)
            {
                if (vis[j] == 0)
                {
                    f = 1;
                    vis[j] = 1;
                    col[j] = c;
                }
            }
        }

        ll m = 0;
        f(0, n) m = max(m, col[arr[i]]);
        cout << m << "\n";
        f(0, n)
                cout
            << col[arr[i]] << " ";
        cout << "\n";
    }
}