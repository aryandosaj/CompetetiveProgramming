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
ll dp[2001][2001];
ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    if (r == 1)
        return n;
    if (r == 0)
        return 1;
    if (r == n)
        return 1;
    if (dp[n][r] != 0)
        return dp[n][r];
    else
        return dp[n][r] = (ncr(n - 1, r - 1) + ncr(n - 1, r)) % MAX;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    if (2 * k > min(n - 1, m - 1))
    {
        cout << "0";
        return 0;
    }
    cout << (ncr(n - 1, 2 * k) * ncr(m - 1, 2 * k)) % MAX;
}