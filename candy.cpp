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
unordered_map<ll, ll> visit;
void dfs(ll u)
{
    visit[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!visit[v])
        {
            dfs(v);
        }
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
        for (ll j = 1; j <= n; j++)
        {
            ll x;
            cin >> x;
            if (x)
            {
                graph[i].push_back(j+n);
                graph[j+n].push_back(i);
            }
        }
    }
    ll c = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (graph[i].size() > 0)
            if (visit[i] == 0)
            {
                // cout<<i;
                c++;
                dfs(i);
            }
    }
    cout << c;
}