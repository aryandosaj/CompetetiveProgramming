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
ll deg[505];
vll graph[505];
ll link[501][501];
ll inp[501][501];
ll inpdeg[501];
void dfs(ll u, ll k)
{
    for (auto i : graph[u])
    {
        if (!link[u][i])
        {
            if (deg[u] + deg[i] >= k)
            {
                link[u][i] = 1;
                link[i][u] = 1;
                deg[u]++;
                deg[i]++;
                dfs(i, k);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        link[u][v] = 1;
        link[v][u] = 1;
        inp[u][v] = 1;
        inp[v][u] = 1;
        deg[u]++;
        deg[v]++;
        inpdeg[u]++;
        inpdeg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (!link[i][j])
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    ll high = 1000, low = 0, mid, ans=0;
    while (low <= high)
    {
        
        mid = (low + high) / 2;
        // cout<<mid<<"\n";
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] < n - 1)
                dfs(i, mid);
        }
        ll flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] < n - 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            high = mid - 1;
        }
        else
            ans = mid,low = mid + 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                link[i][j] = inp[i][j];
            }
            deg[i] = inpdeg[i];
        }
    }
    cout<<ans;
}