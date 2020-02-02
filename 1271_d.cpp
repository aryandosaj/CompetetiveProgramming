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
ll a[5005];
ll b[5005];
ll c[5005];
vll graph[5005];
ll vis[5005];
ll def[5005];
bool compare(ll a, ll b) { return c[a] > c[b]; }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    f(1, n + 1) cin >> a[i] >> b[i] >> c[i];
    f(0, m)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v);
    }
    f(1, n + 1) sort(graph[i].begin(), graph[i].end(), compare);

    ll cur = 0;
    set<pl> s;
    f(1, n + 1)
    {
        if (k >= a[i])
        {
            cur += c[i];
            k += b[i];
            k--;
            s.insert({c[i], i});
            for (auto j : graph[i])
            {
                if (def[j] == 0 && k>0)
                {
                    def[j] = 1;
                    cur += c[j];
                    s.insert({c[j], j});
                    k--;
                }
            }
        }
        else
        {   
            ll ex = 0;
            for (auto j : graph[i])
            {
                if (def[j])
                    ex++;
            }
            // cout<<i<<" "<<ex<<"\n";
            if (k + ex >= a[i])
            {
                cur += c[i];
                k += b[i];
                k--;
                s.insert({c[i], i});
                for (auto j : graph[i])
                {
                    if (def[j] == 0 && k>0)
                    {
                        def[j] = 1;
                        cur += c[j];
                        k--;
                        s.insert({c[j], j});
                    }
                }
            }
            else
            {
                for (auto j : graph[i])
                    vis[j] = 1;
                pll temp;
                ll hogaya = 0;
                for (auto j : s)
                {
                    if (vis[j.second] || (def[j.second] == 0))
                        continue;
                    temp.push_back(j);
                    k++;
                    if (k + ex >= a[i])
                    {
                        hogaya = 1;
                        break;
                    }
                }
                for (auto j : graph[i])
                    vis[j] = 0;
                if (hogaya)
                {
                    for (auto j : temp)
                    {
                        s.erase(j);
                        def[j.second] = 0;
                        cur -= j.first;
                    }
                    k += b[i];
                    k--;
                    cur += c[i];
                    s.insert({c[i], i});
                    for (auto j : graph[i])
                    {
                        if (def[j] == 0 && k>0)
                        {
                            k--;
                            def[j] = 1;
                            cur += c[j];
                            s.insert({c[j], j});
                        }
                    }
                }
                else
                {
                    cout << "-1";
                    return 0;
                }
            }
        }
        // deb(k);
        // deb(cur);

        def[i] = 1;
    }
    ll ans = 0;
    vll temp;
    f(1, n + 1)
    {
        if (def[i])
            temp.push_back(c[i]);
    }
    // sort(temp,temp)
    cout << cur;

    return 0;
}