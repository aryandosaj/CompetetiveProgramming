#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
vll nobda[100005];
vll pros[100005];
unordered_map<ll, ll> level_n;
unordered_map<ll, ll> level_p;
unordered_map<ll, ll> child_n;
unordered_map<ll, ll> child_p;
unordered_map<ll, ll> visit_n;
unordered_map<ll, ll> visit_p;

ll n, parent[100050], p[100050][32];
ll parent1[100050], p1[100050][32];
ll dp[100050][32];
ll dp1[100050][32];
void dfs_q1(ll x, ll pr)
{
    if (pr != -1)
        level_p[x] = level_p[pr] + 1;
    parent1[x] = pr;
    for (ll i = 0; i < pros[x].size(); i++)
        if (pros[x][i] != pr)
            dfs_q1(pros[x][i], x);
}

void pre1()
{
    memset(p1, -1, sizeof(p1));
    for (ll i = 1; i < n + 1; i++)
        p1[i][0] = parent1[i], dp1[i][0] = 1;
    for (ll j = 1; (1 << j) < n; j++)
    {
        for (ll i = 1; i < n + 1; i++)
        {
            if (p1[i][j - 1] != -1)
            {
                p1[i][j] = p1[p1[i][j - 1]][j - 1];
                dp1[i][j] = dp1[i][j - 1] + dp1[p[i][j - 1]][j - 1];
                //           cout<<dp1[p[i][j-1]][j-1]<<" "<<dp1[i][j]<<"--------\n";
            }
        }
    }
}

ll lca1(ll u, ll v)
{
    ll k = 0;
    if (level_p[u] < level_p[v])
        swap(u, v);
    ll d = level_p[u] - level_p[v];
    while (d)
    {
        ll raise = log2(d);
        k += dp1[u][raise];
        u = p1[u][raise];
        d -= (1 << raise);
    }
    if (u == v)
        return k;
    for (ll j = 31; j >= 0; j--)
        if (p1[u][j] != -1 && p1[u][j] != p1[v][j])
        {
            k += dp1[u][j];
            u = p1[u][j];
            k += dp1[v][j];
            v = p1[v][j];
        }
    k += 2;
    return k;
}

void dfs_q(ll x, ll pr)
{
    if (pr != -1)
        level_n[x] = level_n[pr] + 1;
    parent[x] = pr;
    for (ll i = 0; i < nobda[x].size(); i++)
        if (nobda[x][i] != pr)
            dfs_q(nobda[x][i], x);
}

void pre()
{
    memset(p, -1, sizeof(p));
    for (ll i = 1; i < n + 1; i++)
        p[i][0] = parent[i], dp[i][0] = 1;
    for (ll j = 1; (1 << j) < n; j++)
    {
        for (ll i = 1; i < n + 1; i++)
        {
            if (p[i][j - 1] != -1)
            {
                p[i][j] = p[p[i][j - 1]][j - 1];
                dp[i][j] = dp[i][j - 1] + dp[p[i][j - 1]][j - 1];
                //           cout<<dp[p[i][j-1]][j-1]<<" "<<dp[i][j]<<"--------\n";
            }
        }
    }
}

ll lca(ll u, ll v)
{
    ll k = 0;
    if (level_n[u] < level_n[v])
        swap(u, v);
    ll d = level_n[u] - level_n[v];
    while (d)
    {
        ll raise = log2(d);
        k += dp[u][raise];
        u = p[u][raise];
        d -= (1 << raise);
    }
    if (u == v)
        return k;
    for (ll j = 31; j >= 0; j--)
        if (p[u][j] != -1 && p[u][j] != p[v][j])
        {
            k += dp[u][j];
            u = p[u][j];
            k += dp[v][j];
            v = p[v][j];
        }
    k += 2;
    return k;
}

void dfs_n(ll u)
{
    visit_n[u] = 1;
    child_n[u]++;
    for (ll i = 0; i < nobda[u].size(); i++)
    {
        ll v = nobda[u][i];
        if (!visit_n[v])
        {
            // level_n[v] = level_n[u]+1;
            dfs_n(v);
            child_n[u] += child_n[v];
        }
    }
}
void dfs_p(ll u)
{
    visit_p[u] = 1;
    child_p[u]++;
    for (ll i = 0; i < pros[u].size(); i++)
    {
        ll v = pros[u][i];
        if (!visit_p[v])
        {
            level_p[v] = level_p[u] + 1;
            dfs_p(v);
            child_p[u] += child_p[v];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        nobda[a].push_back(b);
        nobda[b].push_back(a);
    }
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        pros[a].push_back(b);
        pros[b].push_back(a);
    }
    ll t;
    ll pr = 0, no = 0;
    dfs_q(1, -1);
    dfs_q1(1, -1);
    pre();
    pre1();
    dfs_n(1);
    dfs_p(1);
    while (q--)
    {
        cin >> t;
        ll a, b, p;
        if (t == 1)
        {
            cin >> a >> b >> p;
            no += (lca(a, b)-1) * p;
            pr += (lca1(a, b)-1) * p;
        }
        else
        {
            cin >> a >> p;
            pr += child_p[a] * p;
            no += child_n[a] * p;
        }
    }
    cout<<no<<" "<<pr;
}