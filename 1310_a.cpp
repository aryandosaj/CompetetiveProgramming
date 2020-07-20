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
map<ll, vll> mp;
ll a[200005];
ll t[200005];
set<ll> s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    f(0, n)
            cin >>
        a[i],
        s.insert(a[i]);
    f(0, n)
    {
        cin >> t[i];
        mp[a[i]].pb(t[i]);
    }
    for (auto i : s)
        sort(mp[i].begin(), mp[i].end());
    ll ans = 0;
    multiset<ll> temp;
    ll sum = 0;
    while (s.size())
    {
        ll v = *s.begin();
        s.erase(s.begin());
        for (auto i : mp[v])
            temp.insert(i), sum += i;
        auto p = s.lower_bound(v);
        ll nex = 1e18;
        if (p != s.end())
            nex = *p;
        ll d = nex - v;
        ll siz = min(d, (ll)temp.size());
        ll c = 0;
        while (siz--)
        {
            auto po = prev(temp.end());
            ans += (*po) * c;
            c++;
            sum -= (*po);
            temp.erase(po);
        }

        ans += sum * c;
        // cout << v << " " << d << " " << c << " " << nex << " " << ans <<" "<<temp.size()<<" "<<sum<< "\n";
    }
    cout << ans;
}