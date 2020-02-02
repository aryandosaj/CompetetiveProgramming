#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, c;
        cin >> c >> x;
    
        if (x == 1)
            cout << c << "\n";
        else
        {
            ll ans = 0;
            while (c > 0)
            {
                ans += c % x;
                c /= x;
            }
            cout << ans << "\n";
        }
    }
}