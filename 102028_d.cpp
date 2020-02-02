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
    ld pi = atan(1) * 4;

    while (t--)
    {
        ld a, b, r, d;
        cin >> a >> b >> r >> d;
        d = d * (pi) / 180;
        if (d >= (atan(b / (a + r))))
        {
            ld w = (sqrt(b * b + (a + r) * (a + r)) - r);
            cout << setprecision(20) << w << "\n";
        }
        else
        {
            ld o = atan(b / (a + r)) - d;
            ld w = sqrt(b * b + (a + r) * (a + r)) - r / cos(o);
            w = w*cos(o);
            cout << setprecision(20)<< w << "\n";
        }
    }
}