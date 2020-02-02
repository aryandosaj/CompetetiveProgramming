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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, t;
    cin >> n;
    map<ll, ll> mp;
    vll v;
    t = n;
    while (t--)
    {
        ll x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
    }
    sort(v.begin(), v.end());
    ll i = n - 1;
    ll ans = n;
    ll j =n/2-1;
    unordered_map<ll, ll> vis;
    while (j >= 0 && i >= 0)
    {
            if (v[i] >= 2 * v[j])
            {
                vis[j] = 1;
                j--;
                i--;
                ans--;
            }
            else
                j--;
    }
    cout << ans;
}