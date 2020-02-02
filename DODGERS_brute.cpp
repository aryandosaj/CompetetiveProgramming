#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define NUM 1000005
vll graph[NUM];
ll tim[NUM];
ll L[NUM];
ll R[NUM];
ll ans[NUM];
bool vis[NUM];
ll bit[NUM][2];

void update(ll i, ll f, ll k)
{
    for (; i < NUM; i += i & -i)
        bit[i][f] += k;
}
ll query(ll i, ll f)
{
    ll sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i][f];
    return sum;
}
vector<pair<ll, pair<ll, ll>>> qu;
ll tt;
void dfs(ll u)
{
    tim[u] = tt++;
    vis[u] = 1;
    for (auto i : graph[u])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}
vll r[NUM];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        tt = 1;

        ll N, M, Q, s;
        cin >> N >> M >> Q >> s;
        qu.clear();
        for (ll i = 0; i < NUM; i++)
        {
            graph[i].clear(), tim[i] = 0, L[i] = 1, R[i] = N, r[i].clear();
            bit[i][0] = 0;
            bit[i][1] = 0;
            vis[i] = 0;
        }
        for (ll j = 0; j < M; j++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (ll i = 1; i <= N; i++)
        {
            if (!vis[i])
                dfs(i);
        }
        for (ll i = 1; i <= N; i++)
        {
            for (auto j : graph[i])
            {

                if (tim[j] < tim[i])
                {
                    if (j < i)
                    {
                        L[i] = max(L[i], j + 1);
                    }
                    else
                    {
                        R[i] = min(R[i], j - 1);
                    }
                }
            }
            r[R[i]].push_back(L[i]);
        }

        for (ll i = 0; i < Q; i++)
        {
            ll l, r;
            cin >> l >> r;
            if (l > r)
                swap(l, r);
            qu.push_back({l, {r, i}});
        }
        sort(qu.begin(), qu.end());
        ll indl = 1;
        ll indr = 1;
        ll cnt = 0;
        for (auto i : qu)
        {
            while (indl <= i.first)
            {
                update(L[indl], 0, -1);
            }
            while (indr <= i.second.first)
            {
                update(L[indl], 0, -1);
            }
            ans[i.second.second] = (i.first - i.second.first + 1) - (query(i.first, 0) - query(i.second.first, 0));
        }
        for (int i = 0; i < Q; i++)
        {
            cout << ans[i] << "\n";
        }
    }
}