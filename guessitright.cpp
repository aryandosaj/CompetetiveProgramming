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
        ll n, k, m;
        cin >> n >> k >> m;
        if ((n > k) && (m > 1))
            n -= k * floor((n - 1) / k), m--;
                                                                                                                                       

        ll p, q;
        ll x = ceil(m / (2.0));

        if (m == 1)
        {
            p = 1;
            q = n;
        }
        else
        {

            p = ((power(n, x, MAX)) - (power(n - 1, x, MAX))+MAX)%MAX;
            q = (power(n, x, MAX));
        }
        if (!(m & 1))
        {
            p = ((p * (n + k)) % MAX + (power(n - 1, x, MAX))) % MAX;
            (q *= (n + k))%=MAX;
        }
        ll ans = (p * power(q, MAX - 2, MAX)) % MAX;
        cout << ans << "\n";
        // cout << (p / (q * 1.0)) << "\n";
    }
}