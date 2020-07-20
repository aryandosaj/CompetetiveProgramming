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

stack<ll> st;
vll adj[1000006];
vll radj[1000006];
ll col[1000006];
ll parent[1000006];
ll siz[1000006];
ll vis[1000006];
ll val[1000006];
void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
void dfs(ll u)
{
    // cout<<u<<"\n";
    vis[u] = 1;
    for (auto i : adj[u])
        if (vis[i] == 0)
            dfs(i);
    st.push(u);
}
void dfs1(ll u, ll c)
{
    // cout<<u<<" ";
    vis[u] = 1;
    for (auto i : radj[u])
        if (vis[i] == 0)
            union_sets(u, i), dfs1(i, ++c);
}
ll nex(ll x, ll d)
{
    if (x == 1)
        return d;
    return x - 1;
}
void dfs2(ll u, ll c, ll s)
{
    // cout<<u<<"\n";
    vis[u] = 1;

    val[c] = val[c] | col[u];
    // cout << c << " " << u << " " << val[c] << " " << col[u] << "\n";
    for (auto i : radj[u])
        if (vis[i] == 0)
            dfs2(i, nex(c, s), s);
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
        ll n, m;
        cin >> n >> m;

        f(0, n * m) make_set(i), val[i] = 0, adj[i].clear(), radj[i].clear(), col[i] = 0, vis[i] = 0;
        string s[n];
        string c[n];
        f(0, n) cin >> c[i];
        f(0, n)
        {
            cin >> s[i];
            fi(0, s[i].length())
            {
                ll u = i * m + j;
                col[u] = 1 - (c[i][j] - '0');
                if (s[i][j] == 'U')
                    adj[u].pb((i - 1) * m + j), radj[(i - 1) * m + j].pb(u);
                if (s[i][j] == 'D')
                    adj[u].pb((i + 1) * m + j), radj[(i + 1) * m + j].pb(u);
                if (s[i][j] == 'L')
                    adj[u].pb(i * m + j - 1), radj[i * m + j - 1].pb(u);
                if (s[i][j] == 'R')
                    adj[u].pb(i * m + j + 1), radj[i * m + j + 1].pb(u);
            }
        }
        f(0, n * m) if (vis[i] == 0)
            dfs(i);
        // return 0;
        f(0, n * m) vis[i] = 0;
        while (!st.empty())
        {
            ll u = st.top();
            st.pop();
            if (vis[u] == 0)
                dfs1(u, 1);
        }
        f(0, n * m) vis[i] = 0;
        ll ans1 = 0, ans2 = 0;
        f(0, n * m)
        {
            if (vis[i])
                continue;
            ll p = find_set(i);
            // cout << p << " " << siz[p] << "\n";
            if (siz[p] > 1)
            {
                ans1 += siz[p];
                fi(0, siz[p] + 1) val[j] = 0;
                dfs2(i, 1, siz[p]);
                fi(0, siz[p] + 1) ans2 += val[j];
            }
        }
        cout << ans1 << " " << ans2 << "\n";
    }
}