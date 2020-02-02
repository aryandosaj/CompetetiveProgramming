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
ll dp[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    for (ll i = 1; i <= q; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll ans = 0;
        for (ll j = 1; j*j <= (x); j++)
        {
            if (x % j == 0)
            {
                if (dp[j] < i - y)
                    ans++; dp[j] = i;
                if (dp[x / j] < i - y)
                    ans++;dp[x / j] = i;
            }
        }
        cout << ans<<"\n";
    }
}