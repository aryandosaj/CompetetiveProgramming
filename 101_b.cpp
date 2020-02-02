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
    ll u, v;
};
bool comp(dt a, dt b)
{
    return a.v < b.v;
}
ll bit[100005];
void update(ll x, ll v)
{
    // if(x==0)x++;
    for (ll i = x; i < 100005; i += i & -i)
        bit[i] += v,bit[i]%=MAX;
}
ll query(ll x)
{
    ll ret = 0;
    for (ll i = x; i > 0; i -= i & -i)
        ret += bit[i],ret%=MAX;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<dt> bus;
    vll end;
    // end[0] = 0;
    end.push_back(0);
    unordered_map<ll, ll> dp;
    unordered_map<ll, ll> mp;
    unordered_map<ll, ll> vis;
    mp[0] = 1;
    dp[0] = 1;
    update(1,1);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        dt t;
        t.u = u;
        t.v = v;
        if(vis[v]==0)end.push_back(v),vis[v]=1;
        bus.push_back(t);
    }
    sort(bus.begin(), bus.end(), comp);
    sort(end.begin(),end.end());
    ll ans=0;
    for (ll i = 1; i <end.size(); i++)
        if(end[i]>end[i-1])mp[end[i]] = mp[end[i-1]]+1;
    for (auto i : bus)
    {
        ll start = lower_bound(end.begin(), end.end(), i.u) - end.begin();
        ll stop = lower_bound(end.begin(), end.end(), i.v) - end.begin();
        stop--;
        //    cout<<i.v<<" "<<start<<" "<<stop<<"\n";
        ll dif =query(mp[end[stop]])-query(mp[end[start]]-1);
        // cout<<dif<<" ";
        update(mp[i.v],dif);
        // ll dif2 = 0;
        // while (start <= stop)
        //     dif2 += dp[end[start++]];
        // dp[i.v]+=dif2;
        
        // cout<<dif2<<"\n";
        
    }
    cout << (query(mp[n])-query(mp[n]-1)+MAX)%MAX;
}