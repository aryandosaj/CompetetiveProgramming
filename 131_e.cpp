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
struct dt
{
    ll r, c;
};
vector<dt> v[100005];
vector<dt> h[100005];
vector<dt> d1[200005];
vector<dt> d2[200005];
ll ans[100005];
vector<dt>poi;
unordered_map<ll, unordered_map<ll, ll>> point;
bool compc(dt a, dt b)
{
    return a.c < b.c;
}
bool compr(dt a, dt b)
{
    return a.r < b.r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll r, c;
        cin >> r >> c;
        dt t;
        t.r = r;
        t.c = c;
        poi.push_back(t);
        h[r].push_back(t);
        v[c].push_back(t);
        d1[r + c].push_back(t);
        d2[n + (r - c)].push_back(t);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (h[i].size() > 1)
        {
            sort(h[i].begin(), h[i].end(), compc);
            for (ll j = 0; j < h[i].size(); j++)
            {
                dt p = h[i][j];
                if ((j == 0) || (j == (h[i].size() - 1)))
                    point[p.r][p.c]++;
                else
                    point[p.r][p.c] += 2;
            }
        }
        if (v[i].size() > 1)
        {
            sort(v[i].begin(), v[i].end(), compr);
            for (ll j = 0; j < v[i].size(); j++)
            {
                dt p = v[i][j];
                if ((j == 0) || (j == (v[i].size() - 1)))
                    point[p.r][p.c]++;
                else
                    point[p.r][p.c] += 2;
            }
        }
    }
    for (ll i = 1; i <= 2 * n; i++)
    {
        if (d1[i].size() > 1)
        {
            sort(d1[i].begin(), d1[i].end(), compc);
            for (ll j = 0; j < d1[i].size(); j++)
            {
                dt p = d1[i][j];
                if ((j == 0) || (j == (d1[i].size() - 1)))
                    point[p.r][p.c]++;
                else
                    point[p.r][p.c] += 2;
            }
        }

        if (d2[i].size() > 1)
        {
            sort(d2[i].begin(), d2[i].end(), compc);
            for (ll j = 0; j < d2[i].size(); j++)
            {
                dt p = d2[i][j];
                if ((j == 0) || (j == (d2[i].size() - 1)))
                    point[p.r][p.c]++;
                else
                    point[p.r][p.c] += 2;
            }
        }
    }
    for(auto i:poi)
    {
        ans[point[i.r][i.c]]++;
    }
    for(ll i=0;i<9;i++)
    {
        cout<<ans[i]<<" ";
    }
}