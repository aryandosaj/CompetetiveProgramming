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
double dp[5005][5005];
double p[5005];
ll tt[5005];
double fun(ll i, ll j)
{
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    double ans = 0;
    double temp=1;
    for (ll k = 1; (k <= tt[i]) && (k <= j); k++)
    {
        if(k!=tt[i])
        ans += fun(i - 1, j - k) * temp * p[i];
        else
        ans += fun(i - 1, j - k)*temp;
        temp*=(1-p[i]);
    }
    dp[i][j] = ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 0; i < 5005; i++)
        for (ll j = 0; j < 5005; j++)
            dp[i][j] = -1;
    ll n, t;
    cin >> n >> t;
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i] >> tt[i];
        p[i] /= 100.0;
    }
    double ans=0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= t; j++)
        {
            ans+= fun(i, j);
        }
    }
    cout<<setprecision(15)<<ans;
}