#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll ans[n];
    set<ll> s;
    vll erase;
    for (ll i = 0; i < n; i++)
        s.insert(i );
    for (ll i = 0; i < m; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        l--,r--,x--;
        auto p = s.lower_bound(l);
        // cout<<*p<<"hh";
        while (p != s.end())
        {
            ll val = *p;
            if (val > r)
                break;
            if(val!=x){erase.push_back(val);
            ans[val]=x;}
            p++;
            // cout<<val<<" ";
        }
        
        for(auto j :erase) s.erase(j);
        erase.clear();
        // s.insert(x);
    }
    for(auto i:s)ans[i]=-1;
    for (auto i : ans)
        cout << i+1<<" ";
}