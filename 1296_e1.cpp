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
map<char, vll> mp;
map<ll, ll> col;
ll vis[205];
vll adj[205];
ll cc[205];
void dfs(ll u, ll c)
{
    vis[u] = 1;
    for (auto i : adj[u])
    {
        if (vis[i] == 0)
        {
            cc[i] = (1 - c);
            dfs(i, (1 - c));
        }
        else
        {
            if (cc[i] == cc[u])
            {
                cout << "NO\n";
                exit(0);
            }
        }
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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    f(0, n)
    {
        fi(i + 1, n)
        {
            if (s[i] > s[j])
                adj[i].pb(j),
                    adj[j].pb(i);
        }
    }
    f(0, n)
    {
        if (vis[i] == 0)
            dfs(i, 0);
    }
    cout<<"YES\n";
    f(0,n)
    cout<<cc[i];
    
}