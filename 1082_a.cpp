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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y, d, s1 = MAX, s2 = MAX, s3 = MAX;
        cin >> n >> x >> y >> d;
        if (abs(x - y) % d == 0)
            s1 = abs(x - y) / d;
        if ((n - y) % d == 0)
            s2 = (n - x) / d + ((n - x) % d == 0 ? 0 : 1) + (n - y) / d;
        if ((y - 1) % d == 0)
            s3 = (x - 1) / d + ((x - 1) % d == 0 ? 0 : 1) + (y - 1) / d;
        if (min(s1, min(s2, s3)) == MAX)
        {
            cout << "-1\n";
            continue;
        }
        cout << min(s1, min(s2, s3)) << "\n";
    }
}