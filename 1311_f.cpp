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
pll v;
ll arr[200005];
map<ll, ll> mp;
map<ll, ll> rmp;
pl bit[200005];
set<ll> s;

void insert(ll ind)
{
    for (ll i = ind; i < 200005; i += i & -i)
        bit[i].first += 1, bit[i].second += rmp[ind];
}
pl query(ll ind)
{
    pl ret = {0, 0};
    if(ind==0)return ret;
    for (ll i = ind; i > 0; i -= i & -i)
        ret.first += bit[i].first, ret.second += bit[i].second;
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
    f(0, n)
            cin >>
        arr[i],
        s.insert(arr[i]);
    ll c = 1;
    for (auto i : s)
        rmp[c] = i, mp[i] = c++;
    f(0, n)
    {
        ll ve;
        cin >> ve;
        v.pb({ve, mp[arr[i]]});
    }
    sort(v.begin(), v.end(),greater<pl>());
    ll ans = 0;
    c = 0;
    ll val=0;
    for (auto i : v)
    {
        pl q = query(i.second);
        ll num = c - q.first;
        ll sum = val - q.second;
        // cout<<num<<" "<<sum<<"\n";
        ans+=(sum-num*rmp[i.second]);
        c++;
        val+=rmp[i.second];
        insert(i.second);
    }
    cout<<ans<<"\n";
}