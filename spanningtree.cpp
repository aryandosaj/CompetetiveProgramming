#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll ll
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
ll dsu[1003];
ll siz[1003];
ll wei[1003];
ll find(ll a)
{
    while (a != dsu[a])
        a = dsu[a];
    return a;
}
void join(ll a, ll b, ll w)
{
    a = find(a);
    b = find(b);
    if (siz[a] < siz[b])
        swap(a, b);
    siz[a] += siz[b];
    wei[a] += wei[b] + w;
    dsu[b] = a;
}
class compare
{
public:
    bool operator()(ll a, ll b)
    {
        return siz[find(a)] < siz[find(b)];
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n;
    cin >> n;
    set<pair<ll,ll>> pq;
    for (int i = 1; i <= n; i++)
        dsu[i] = i, siz[i] = 1, pq.insert({1,i}), wei[i] = 0;
    while (!pq.empty())
    {
        auto p = pq.begin();
        pair<ll,ll> temp = *p;
        pq.erase(p);
        ll d = find(temp.second);
        // cout << siz[d] << " " << d << "\n";
        if (siz[d] == n)
        {
            cout << "2 " << wei[d] << endl;
            return 0;
        }
        cout << "1 " << siz[d] << " " << n - siz[d] << "\n";
        for (int i = 1; i <= n; i++)
            if (find(i) == d)
                cout << i << " ";
        cout << "\n";
        for (int i = 1; i <= n; i++)
            if (find(i) != d)
                cout << i << " ";
        cout << endl;
        ll u, v, w;
        cin >> u >> v >> w;
        if (u != -1)
        {
            ll t1 = find(u);
            ll t2 = find(v);
            for(int i=1;i<=n;i++)
            {
                ll x = find(i);
                if(x==t1||x==t2)pq.erase({siz[i],i});
            }
            join(u, v, w);
            d = find(d);
            pq.insert({siz[d],d});
        }
    }
}