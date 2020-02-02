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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    set<pair<ll, pair<ll, ll>>> s;
    map
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            auto p = s.end();
            ll size = (*p).first;
            ll s1, s2;
            if (size & 1)
                s1 = size / 2;
            else
                s1 = size / 2 - 1;
            ll l = (*p).second.first;
            ll r = ((*p).second.first + (*p).second.second) / 2;
            pair<ll, pair<ll, ll>> temp = {size, {l, r - 1}};
            pair<ll, pair<ll, ll>> temp2 = {size, {, r}};
        }
        else
        {
        }
    }
}