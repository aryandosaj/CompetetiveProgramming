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
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, bb, c, l, b, h;
        cin >> a >> bb >> c >> l >> b >> h;
        vector<ll> v;
        v.push_back(a);
        v.push_back(bb);
        v.push_back(c);
        int ans = 0;
        int hh = 6;
        while (hh--)
        {
            if (v[0] <= h && v[1] <= l && v[2] <= b)
                ans += 2;
            next_permutation(v.begin(),v.end());
        }
        cout << ans << "\n";
    }
}