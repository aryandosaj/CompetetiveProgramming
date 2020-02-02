#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
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
ostream &operator<<(ostream &os, multiset<T> S)
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

ll n, blockSize, a[100005], add[350], mul[350];
multiset<pair<ll, ll>> s[350];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    blockSize = sqrt(n);
    f(0, n) cin >> a[i], s[i / blockSize].insert({a[i], i});
    f(0, 350) mul[i] = 1;
    ll q;
    cin >> q;
    while (q--)
    {
        ll c;
        cin >> c;
        if (c == 1 || c == 2)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            if (l > r)
                swap(l, r);
            l--, r--;
            ll lBlock = l / blockSize, rBlock = r / blockSize;
            if (lBlock == rBlock)
            {
                f(l, n)
                {
                    if (i / blockSize != lBlock)
                        break;
                    s[i / blockSize].erase(s[i / blockSize].find({a[i], i}));
                    a[i] *= mul[i / blockSize], a[i] += add[i / blockSize];
                    s[i / blockSize].insert({a[i], i});
                }
                fr(l - 1, 0)
                {
                    if (j / blockSize != lBlock)
                        break;
                    s[j / blockSize].erase(s[j / blockSize].find({a[j], j}));
                    a[j] *= mul[j / blockSize], a[j] += add[j / blockSize];
                    s[j / blockSize].insert({a[j], j});
                }
                add[lBlock] = 0, mul[lBlock] = 1;
                f(l, r + 1)
                {
                    if (c == 1)
                        s[lBlock].erase(s[lBlock].find({a[i], i})), a[i] += x, s[lBlock].insert({a[i], i});
                    else
                        s[lBlock].erase(s[lBlock].find({a[i], i})), a[i] *= x, s[lBlock].insert({a[i], i});
                }
            }
            else
            {
                f(l, n)
                {
                    if (i / blockSize != lBlock)
                        break;
                    s[i / blockSize].erase(s[i / blockSize].find({a[i], i}));
                    a[i] *= mul[i / blockSize], a[i] += add[i / blockSize];
                    if (c == 1)
                        a[i] += x;
                    else
                        a[i] *= x;
                    s[i / blockSize].insert({a[i], i});
                }
                fr(l - 1, 0)
                {
                    if (j / blockSize != lBlock)
                        break;
                    s[j / blockSize].erase(s[j / blockSize].find({a[j], j}));
                    a[j] *= mul[j / blockSize], a[j] += add[j / blockSize];
                    s[j / blockSize].insert({a[j], j});
                }
                add[lBlock] = 0, mul[lBlock] = 1;
                fr(r, 0)
                {
                    if (j / blockSize != rBlock)
                        break;
                    s[j / blockSize].erase(s[j / blockSize].find({a[j], j}));
                    a[j] *= mul[j / blockSize], a[j] += add[j / blockSize];
                    if (c == 1)
                        a[j] += x;
                    else
                        a[j] *= x;
                    s[j / blockSize].insert({a[j], j});
                }
                f(r + 1, n)
                {
                    if (i / blockSize != rBlock)
                        break;
                    s[i / blockSize].erase(s[i / blockSize].find({a[i], i}));
                    a[i] *= mul[i / blockSize], a[i] += add[i / blockSize];
                    s[i / blockSize].insert({a[i], i});
                }
                add[rBlock] = 0, mul[rBlock] = 1;
                lBlock++;
                while (lBlock != rBlock)
                {
                    if (c == 1)
                        add[lBlock] += x;
                    else
                        mul[lBlock] *= x, add[lBlock] *= x;
                    lBlock++;
                }
            }
        }
        else
        {
            ll x;
            cin >> x;
            ll l = -1, r = -1;
            ll mx = (n - 1) / blockSize, cur = 0;
            while (cur <= mx)
            {
                ll y = x;
                if (add[cur])
                    y -= add[cur];
                if (y < 0)
                {
                    cur++;
                    continue;
                }
                if (mul[cur])
                {
                    if (y % mul[cur] == 0)
                        y /= mul[cur];
                    else
                    {
                        cur++;
                        continue;
                    }
                }
                auto it = s[cur].lower_bound({y, -1e18});
                if (it != s[cur].end() && it->first == y)
                {
                    l = it->second;
                    break;
                }
                cur++;
            }
            if (l == -1)
            {
                cout << "-1\n";
                continue;
            }
            cur = mx;
            while (cur >= 0)
            {
                ll y = x;
                if (add[cur])
                    y -= add[cur];
                if (y < 0)
                {
                    cur--;
                    continue;
                }
                if (mul[cur])
                {
                    if (y % mul[cur] == 0)
                        y /= mul[cur];
                    else
                    {
                        cur--;
                        continue;
                    }
                }
                auto it = s[cur].lower_bound({y + 1, -1e18});
                if (it != s[cur].begin())
                {
                    it--;
                    if (it->first == y)
                    {
                        r = it->second;
                        break;
                    }
                }
                cur--;
            }
            cout << r - l + 1 << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    cout
        << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}