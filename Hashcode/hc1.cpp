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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll bpd[100050], st[100050]; // books per day
pll p;
ll c[100050], mx[100050]; // c: iss book k liye knsa lib chahie
pll books[100050];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("din.txt", "rt", stdin);
    freopen("d.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll b, l, d;
    cin >> b >> l >> d; // books, libraries, days
    p.resize(b);
    f(0, b) cin >> p[i].first, p[i].second = i; // score, bookID
    f(0, b) mx[i] = 1e18;
    vector<pair<double, ll>> xxx;
    f(0, l)
    {
        ll n; // number of books, signup time, books per day
        cin >> n >> st[i] >> bpd[i];
        double xx = 0;
        fi(0, n)
        {
            ll x;
            cin >> x;
            xx += p[x].first;
            books[i].pb({p[x].first, x});
            if (mx[x] > st[i])
                mx[x] = st[i], c[x] = i;
        }
        xx *= xx * 1.0;
        xx *= bpd[i];
        xx /= n * 1.0;
        xx /= st[i] * 1.0 * st[i];
        xxx.pb({xx, i});
        sort(books[i].begin(), books[i].end());
    }
    sort(xxx.begin(), xxx.end());
    reverse(xxx.begin(), xxx.end());
    sort(p.begin(), p.end());
    vector<pair<ll, pair<ll, vll>>> ans;
    ll maxx = 0;
    for (ll z = 0; z < 1000; z++)
    {
        vector<pair<ll, pair<ll, vll>>> currentAns;
        ll tot = 0;
        vll order;
        f(0, l) order.pb(xxx[i].second);
        ll ct = 0;
        ll ppp = sqrt(l);
        ppp = sqrt(ppp);
        ppp = sqrt(ppp);
        ppp = sqrt(ppp);
        ppp = sqrt(ppp);
        vector<ll> permutation(ppp);
        for (ll i = 0; i < ppp; i++)
            permutation[i] = i;
        shuffle(permutation.begin(), permutation.end(), rng);
        vll order1;
        order1.resize(l);
        f(0, ppp) order1[permutation[i]] = order[i];
        f(ppp, l) order1[i] = order[i];
        order.clear();
        order = order1;
        order1.clear();
        f(0, order.size())
        {
            if (ct + st[order[i]] < d)
            {
                order1.pb(order[i]);
                ct += st[order[i]];
            }
        }
        order.clear();
        order = order1;
        bool done[b + 5];
        memset(done, false, sizeof(done));
        ct = 0;
        f(0, order.size())
        {
            vll bts; // books to be scanned
            ct += st[order[i]];
            ll rem = d - 1 - ct;
            ll cp = books[order[i]].size() - 1, count = 0;
            while (cp >= 0 && rem > 0)
            {
                if (done[books[order[i]][cp].second])
                {
                    cp--;
                    continue;
                }
                done[books[order[i]][cp].second] = true;
                count++;
                tot += books[order[i]][cp].first;
                bts.pb(books[order[i]][cp].second);
                cp--;
                if (count % bpd[order[i]] == 0)
                    rem--;
            }
            if (bts.size() == 0)
                continue;
            currentAns.pb({order[i], {bts.size(), bts}});
        }
        if (tot > maxx)
            maxx = tot, ans = currentAns;
    }
    cout << ans.size() << "\n";
    f(0, ans.size())
    {
        cout << ans[i].first << " " << ans[i].second.first << "\n";
        fi(0, ans[i].second.second.size()) cout << ans[i].second.second[j] << " ";
        cout << "\n";
    }

    return 0;
}