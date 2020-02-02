#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define deb(x) cout << #x << "  " << x << endl;

//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}
ll fact[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    f(1, 20) fact[i] = fact[i - 1] * i;
    ll t;
    cin >> t;
    while (t--)
    {
        vll v;
        ll n;
        cin >> n;
        ll i = 2;
        map<ll, ll> mp;
        while (n > 0)
        {
            v.pb(n % i);
            mp[n % i]++;
            n /= i++;
        }
        ll ans = 1;
        sort(v.begin(), v.end());
        f(2, v.size() + 2)
        {
            ll c = (lower_bound(v.begin(), v.end(), i) - v.begin());
            ans *= (c - (i - 2));
        }
        for (auto i : mp)
            ans /= fact[i.second];
        ll sub = 0;
        if (v[0] == 0)
        {
            sub = 1;
            vll temp;
            f(1, v.size()) temp.push_back(v[i]);
            f(2, temp.size() + 2)
            {
                ll c = (lower_bound(temp.begin(), temp.end(), i) - temp.begin());
                sub *= c - (i - 2);
            }
            mp[0]--;
            for (auto i : mp)
                sub /= fact[i.second];
        }

        cout << (ans - sub-1) << "\n";
    }
    return 0;
}