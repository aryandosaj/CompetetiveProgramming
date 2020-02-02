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
ll dp[30005];
double pro(double n, double m, double k)
{
    double ans = 0;

    if (m == 0)
        return 0;
    if (m == 1)
    {
        ans = 1 / n;
        return ans;
    }
    if (m > 1)
    {
        if (n > k)
        {
            n -= k * floor((n - 1) / k);
            ans = pro(n, m - 1, k);
            return ans;
        }
    }
    ans += (1 / n) + ((n - 1) / n) * pro(n + k, m - 1, k);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    double n, k, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> m;
        cout << pro(n, m, k) << "\n";
    }
}