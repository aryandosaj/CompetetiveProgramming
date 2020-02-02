#include <bits/stdc++.h>
#include <math.h>
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
unordered_map<ll, unordered_map<ll, ll>> mp;
unordered_map<ll, ll> cnt;
set<ll> s;
ll fac[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        mp[x][i]++;
        s.insert(x);
        cnt[x]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        mp[x][i]++;
        s.insert(x);
        cnt[x]++;
    }
    ll m;
    cin >> m;
    for (ll i = 1; i < 200005; i++)
        fac[i] = (fac[i - 1] * i) % m;
    ll po = 0;
    vll mul;
    for (auto i : s)
    {
        mul.push_back(cnt[i]);
        for (auto j : mp[i])
        {
            po+=(log2(j.second));
        }
    }
    ll ans = 1;
    for (auto i : mul)
    {
        if (po > 0)
        {
            for (ll j = 1; j <= i; j++)
            {
                ll y=j;
                while (po > 0 && (y % 2 == 0))
                {
                    y /= 2;
                    po--;
                }
                ans = (ans * y) % m;
            }
        }
        else
        {
            ans = (ans*fac[i])%m;
        }
        
    }
    cout<<ans;
}