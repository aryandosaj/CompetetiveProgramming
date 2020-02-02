#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
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
ll arr[800010];
ll a1[800010];
set<ll> s;
pll inp;
unordered_map<ll, ll> mp;
void init(ll n)
{
    f(0, 4 * n + 4)
    {
        arr[i] = 0;
        a1[i] = 0;
    }
    s.clear();
    mp.clear();
    inp.clear();
}
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

        ll n;
        cin >> n;
        init(n);
        ll st = mod, en = 0;
        f(0, n)
        {
            ll l, r;
            cin >> l >> r;
            s.insert(l);
            s.insert(r);
            inp.pb({l, r});
        }
        ll c = 1;
        for (auto i : s)
            mp[i] = c++;
        for (auto i : inp)
        {
            ll x = 2 * mp[i.first];
            ll y = 2 * mp[i.second];
            st = min(st, x);
            en = max(en, y);
            arr[x]++;
            arr[y + 1]--;
        }
        f(1, 4 * n + 4) arr[i] += arr[i - 1];
        ll comp = 1;
        f(st, en + 1) if (arr[i] == 0) comp++;
        f(0, 4 * n + 4)
            if (arr[i] == 1 && (i & 1))
                a1[i] = 1;
        f(1, 4 * n + 1) a1[i] += a1[i - 1];
        ll ans = comp - 1;
        for (auto i : inp)
        {
            ll l = 2 * mp[i.first];
            ll r = 2 * mp[i.second];
            if (l == r)
            {
                if (arr[l] > 1)
                    ans = max(ans, comp);
                continue;
            }
            ll c = a1[r - 2] - a1[l + 1] + comp;
            if (arr[l] > 1)
                if (arr[l + 1] == 1)
                    c++;
            if (arr[r] > 1)
                if (arr[r - 1] == 1)
                    c++;
            ans = max(ans, c);
        }
        cout << ans << "\n";
    }
}