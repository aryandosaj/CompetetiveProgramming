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
vll graph[100005];
ll arr[100005];
unordered_map<ll, ll> factor;
unordered_map<ll, ll> vis;
void p_factor(ll n, ll v)
{
    vll f;
    if ((n % 2) == 0)
         f.push_back(2);
    while ((n % 2) == 0)
        n /= 2;
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
             f.push_back(i);
        while (n % i == 0)
            n /= i;
    }
    if (n > 2)
        f.push_back(n);

    for (ll mask = 1; mask < pow(2, f.size()); mask++)
    {
        ll nu = 1;
        ll ma = mask;
        ll p = 0;
        while (ma > 0)
        {
            if (ma % 2)
                nu *= f[p];
            p++;
            ma /= 2;
        }
        factor[nu] += v;
    }
}
struct dt
{
    ll n, c;
};
bool comp(dt a, dt b)
{
    if (a.c == b.c)
        return a.n > b.n;
    else
        return a.c > b.c;
}
vector<dt> ans;
ll x = 0;
void dfs(ll u)
{
    vis[u] = 1;
    if ((graph[u].size() > 1) || (u == 1))
    {
        if (u != 1)
        {
            x++;
            p_factor(arr[u], 1);
        }

        for (ll i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];
            if (vis[v] == 0)
                dfs(v);
        }
        if (u != 1)
        {
            x--;
            p_factor(arr[u], -1);
        }
    }
    else
    {
        ll num = __gcd(arr[1], arr[u]);
        vll f;
        {
            ll n = num;
            if ((n % 2) == 0)
                f.push_back(2);
            while ((n % 2) == 0)
                n /= 2;
            for (ll i = 3; i <= sqrt(n); i += 2)
            {
                if ((n % i) == 0)
                    f.push_back(i);
                while ((n % i) == 0)
                    n /= i;
            }
            if (n > 2)
                f.push_back(n);
        }
        ll temp = 0;
        for (ll mask = 1; mask < pow(2, f.size()); mask++)
        {
            ll nu = 1;
            ll ma = mask;
            ll p = 0;
            while (ma > 0)
            {
                if (ma % 2)
                    nu *= f[p];
                p++;
                ma /= 2;
            }
            if ((__builtin_popcountll(mask) % 2) == 0)
            {
                temp -= factor[nu];
            }
            else
                temp += factor[nu];
        }
        dt r;
        r.c = (x - temp);
        r.n = u;
        ans.push_back(r);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    sort(ans.begin(), ans.end(), comp);
    for (auto i : ans)
    {
        cout << i.n << " ";
    }
}