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
ll a[300005];
ll h[300005];
vector<pair<ll,pair<ll,ll>>> s;
map<pl, ll> mp;
ll ans[300005];
ll bit[300005];
void insert(ll ind)
{
    for (ll i = ind; i < 300005; i += i & -i)
        bit[i] += 1;
}
ll query(ll ind)
{
    ll ret = 0;
    for (int i = ind; i > 0; i -= i & -i)
        ret += bit[i];
    return ret;
}

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
    f(0, n) cin >> a[i] >> h[i], s.pb({a[i], {h[i],i}});
    sort(s.begin(), s.end());
    f(0, n)
    {
        ll ind = s[i].second.second;
        ans[ind] = query(s[i].second.first)-mp[{s[i].first,s[i].second.first}];
        mp[{s[i].first,s[i].second.first}]++;
        insert(s[i].second.first);
        // cout<<s[i].second.first<<" "<<ans[ind]<<"\n";
    }

    f(0,n)
        cout << ans[i] << "\n";
}