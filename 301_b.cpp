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
ll a[201];
struct dt
{
    ll u, v, w;
};
pair<ll, ll> point[201];
ll d;
ll dis(pair<ll, ll> a, pair<ll, ll> b)
{
    return (abs(a.first - b.first) + abs(a.second - b.second)) * d;
}
ll dp[201];
priority_queue<pair<ll, ll>> pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n >> d;
    for (int i = 2; i <= n - 1; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> point[i].first >> point[i].second;
    ll dist[n + 1];
    for (ll i = 2; i <= n; i++)
        dist[i] = MAX;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll u = pq.top().second;
        // cout << u << " " << pq.top().first << "\n";
        pq.pop();
        for (ll i = 2; i <= n; i++)
        {
            if (i != u)
            {
                ll w = dis(point[u], point[i]) - a[u];
                if (dist[i] > dist[u] + w)
                {
                    dist[i] = dist[u] + w;
                    pq.push({-w, i});
                }
            }
        }
    }
    cout << dist[n];
}