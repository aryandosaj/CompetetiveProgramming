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
ll arr[200005];
ll dist[200005];
ll dist1[200005];
ll n;
vll graph[200005];
vll graph1[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    priority_queue<pl, pll, greater<pl>> p, p1;
    f(0, n)
    {
        dist[i] = mod;
        dist1[i] = mod;
        cin >> arr[i];
        if (i + arr[i] < n)
            graph[i + arr[i]].pb(i), graph1[i + arr[i]].pb(i);
        if (i - arr[i] >= 0)
            graph[i - arr[i]].pb(i), graph1[i - arr[i]].pb(i);
        if (arr[i] & 1)
            p.push({0, i}), dist[i] = 0;
        else
            p1.push({0, i}), dist1[i] = 0;
    }
    while (!p.empty())
    {
        pl u = p.top();
        p.pop();
        for (auto i : graph[u.second])
        {
            if (dist[i] > dist[u.second] + 1)
            {
                dist[i] = dist[u.second] + 1;
                p.push({dist[i], i});
            }
        }
    }

    while (!p1.empty())
    {
        pl u = p1.top();
        p1.pop();
        for (auto i : graph1[u.second])
        {
            if (dist1[i] > dist1[u.second] + 1)
            {
                dist1[i] = dist1[u.second] + 1;
                p1.push({dist1[i], i});
            }
        }
    }
    f(0, n) dist[i] += dist1[i];
    f(0, n)
    {
        if (dist[i] >= mod)
            dist[i] = -1;
        cout << dist[i] << " ";
    }

    return 0;
}