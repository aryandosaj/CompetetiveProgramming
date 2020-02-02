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
const int N = 1000006;
vll adj[N];
pll seg;
ll dsu[N];
ll siz[N];
ll find(ll u)
{
    while (dsu[u] != u)
        u = dsu[u];
    return u;
}
void uni(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (siz[a] < siz[b])
        swap(a, b);
    dsu[b] = a;
    siz[a] += siz[b];
}
void init()
{
    f(0, N)
    {
        siz[i] = 1;
        dsu[i] = i;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    ll n;
    cin >> n;
    f(0, n)
    {
        ll l, r;
        cin >> l >> r;
        seg.pb({l, r});
        adj[l].pb(i);
        adj[r].pb(i);
    }
    ll flag = 0;
    set<pl> s;
    f(1, N)
    {
        if (adj[i].size())
        {
            for (auto j : adj[i])
            {
                ll a = find(j);
                auto x = s.find({seg[j].first, j});
                if (x != s.end())
                {
                    // cout<<j<<"\n";
                    for (auto k = next(x); k != s.end(); k = next(k))
                    {
                        // cout<<(*k)<<" ";
                        ll b = find((*k).second);
                        if (a != b)
                        {
                            uni(a, b);
                        }
                        else
                        {
                            // cout<<a<<" "<<b<<" "<<(*k)<<" "<<j<<"\n";
                            cout << "NO";
                            return 0;
                        }
                    }
                    // cout<<"\n";
                    s.erase({seg[j].first, j});
                }
                else
                {
                    s.insert({seg[j].first, j});
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (find(i) != find(i - 1))
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES";
}