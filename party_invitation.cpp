#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
ll fact[200005];
ll inv_fact[200005];
vll graph[200005];
unordered_map<ll, ll> visit;
unordered_map<ll, ll> child;
unordered_map<ll, ll> boss;

void dfs(ll u, ll d)
{
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != d)
        {
            dfs(v, u);
            child[u] += child[v] + 1;
        }
    }
}
ll inv_mod(ll a)
{
    return power(a, MAX - 2, MAX);
}
ll ncr(ll n, ll r)
{
    return ((((fact[n] * inv_mod(fact[r])) % MAX) * inv_mod(fact[n - r])) % MAX);
}
ll rec(ll u, ll n)
{
    visit[u] = 1;
    if (graph[u].size() == child[u])
    {

        for (ll i = 0; i < graph[u].size(); i++)
        {
            visit[graph[u][i]] = 1;
        }
        // cout<<(ncr(n, graph[u].size() + 1) * fact[child[u]]) % MAX;

        return (ncr(n, graph[u].size() + 1) * fact[child[u]]) % MAX;
    }
    n--;
    ll ans = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        ans = (((ans * rec(v, child[v] + 1))%MAX) * ncr(n, child[v] + 1)) % MAX;
        n -= (child[v] + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 200005; i++)
    {
        fact[i] = (i * fact[i - 1]) % MAX;
    }
    inv_fact[200000] = inv_mod(fact[200000]);

    for (ll i = 200000 - 1; i >= 0; i--)
    {
        inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MAX;
    }

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            boss[v] = 1;
        }
        ll ans = 1;
        ll temp = n;

        for (ll i = 1; i <= n; i++)
        {
            if (boss[i] == 0)
                //if (!visit[i])
                {
                    ll dad = i;
                    // cout<<dad;
                    dfs(dad, -1);
                    ans = (((ans * rec(dad, child[dad] + 1)) % MAX) * ncr(temp, child[dad] + 1)) % MAX;
                    temp -= (child[dad] + 1);
                }
        }
        for (ll i = 1; i <= n; i++)
        {
            graph[i].clear();
        }
        cout << ans << "\n";
        visit.clear();
        child.clear();
        boss.clear();
    }
}