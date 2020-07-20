#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
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
ll c[200005];
ll arr[200005];
multiset<pl> s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    f(0, n)
    {
        ll x;
        cin >> x;
        arr[i]=x;
    }
    f(1, k + 1)
            cin >>
        c[i];
    f(0,n)s.insert({c[arr[i]],arr[i]});
    vector<vll> v;
    while (s.size())
    {
        vll a;
        ll mm = 1;
        f (1,n+1)
        {
            auto p = s.lower_bound({mm,0});
            if (p!=s.end())
            {
                pl x = *p;
                a.pb(x.second);
                mm++;
                s.erase(p);
            }
            else break;
        }
        v.pb(a);
        // for (auto i : a)
        //     s.erase(s.find(i));
    }
    cout << v.size() << "\n";
    for (auto i : v)
    {
        cout << i.size() << " ";
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
}