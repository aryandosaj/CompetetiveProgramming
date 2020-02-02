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
pair<ll, pair<ll, ll>> cit[2003];
set<pair<ll, pair<ll, ll>>> s;
ll k[2003];
ll c[2003];
ll dsu[2003];
ll siz[2003];
ll city[2003];
ll find(ll u)
{
    while (dsu[u] != u)
        u = dsu[u];
    return u;
}
void join(ll a, ll b, ll c)
{
    a = find(a);
    b = find(b);
    if (siz[a] < siz[b])
        swap(a, b);
    dsu[b] = a;
    siz[a]+=siz[b];
    city[a] = c;
}
ll dist(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b)
{
    return (k[a.first] + k[b.first]) * (abs(a.second.first - b.second.first) + abs(a.second.second - b.second.second));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll cost = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cit[i].second.first >> cit[i].second.second;
        cit[i].first = i;
        dsu[i] = i;
        city[i]=i;
        siz[i]=1;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i], cost += c[i];
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            s.insert({dist(cit[i], cit[j]), {i, j}});
        }
    }
    vector<pair<ll, ll>> v;
    while (!s.empty())
    {
        auto p = s.begin();
        ll a = (*p).second.first;
        ll b = (*p).second.second;
        ll c1 = a, c2 = b;
        ll temp = ((*p).first);
        s.erase(p);
        // cout<<temp<<" "<<c1<<" "<<c2<<"\n";
        a = city[find(a)];
        b = city[find(b)];
        if (a == b)
            continue;
        if (temp < c[a] && c[a] >= c[b])
        {
            cost -= c[a], cost += temp;
            join(a,b,b);
            v.push_back({c1, c2});
        }
        else if (temp < c[b] && c[b] > c[a])
        {
            cost -= c[b];
            cost += temp;
            join(a,b,a);
            v.push_back({c1, c2});
        }
    }
    set<ll> sta;
    for (int i = 1; i <= n; i++)
        sta.insert(city[find(i)]);
    cout << cost << "\n";
    cout << sta.size() << "\n";
    for (auto i : sta)
        cout << i << " ";
    cout << "\n";
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i.first << " " << i.second << "\n";
}