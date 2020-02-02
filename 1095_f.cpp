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
ll dsu[200005];
vll offer[200005];
struct node
{
    ll a, i;
};
bool comp(node a, node b)
{
    return a.a < b.a;
}
ll parent(ll u)
{
    while (dsu[u] != u)
        u = dsu[u];
    return u;
}
struct dt{
    ll u,v,w;
};
bool ccc(dt a,dt b)
{
    return a.w<b.w;

}
map<ll, map<ll, ll>> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    node arr[n];
    for (ll i = 0; i < 200005; i++)
        dsu[i] = i;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].a;
        arr[i].i = i + 1;
    }
    vector<dt> d;
    sort(arr, arr + n, comp);
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        d.push_back({x,y,w});
        offer[x].push_back(y);
        offer[y].push_back(x);
        mp[x][y] = w;
        mp[y][x] = w;
    }
    // ll start = arr[0].a;
    // ll ans = 0;
    // for (ll i = 1; i < n; i++)
    // {
    //     ll r = start + arr[i].a;
    //     ll u = MAX;
    //     for (ll j = 0; j < offer[arr[i].i].size(); j++)
    //     {
    //         ll v = offer[arr[i].i][j];
    //         if (parent(v) == parent(arr[0].i))
    //         {
    //             if ((mp[arr[i].i][v] != 0))
    //                 u = min(mp[arr[i].i][v], u);
    //         }
    //     }
    //     if ((u < r) && (u != MAX))
    //     {
    //         ans += u;
    //     }
    //     else
    //     {
    //         ans += r;
    //     }
    //     dsu[arr[i].i] = parent(arr[0].i);
    // }
    // cout << ans;
    ll u = arr[0].i;
    for(ll i=1;i<n;i++)
    {
        d.push_back({u,arr[i].i,arr[i].a+arr[0].a});
    }
    sort(d.begin(),d.end(),ccc);
    ll ans=0;
    for(ll i=0;i<d.size();i++)
    {
        if(parent(d[i].u)!=parent(d[i].v)) {ans+=d[i].w;dsu[d[i].u]=parent(d[i].v);}
    }
    cout<<ans;

}