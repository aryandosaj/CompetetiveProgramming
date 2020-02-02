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
ll n, h;
ll dp[40][40];
ll tree(ll nn, ll hh)
{
    if (nn < hh)
        return 0;
    if (dp[nn][hh] != -1)
        return dp[nn][hh];
    ll ans = 0;
    for (ll i = 1; i <= nn; i++)
    {
        ll temp1 = 0;
        for (ll j = 0; j < hh - 1; j++)
        {
            temp1 += tree(i - 1, j);
        }
        temp1 *= tree(nn - i, hh - 1);
        ans += temp1;
        ll temp2 = 0;
        for (ll j = 0; j <= hh - 1; j++)
        {
            temp2 += tree(nn - i, j);
        }
        temp2 *= tree(i - 1, hh - 1);
        ans += temp2;
    }
    return dp[nn][hh] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    for (ll i = 0; i < 40; i++)
        for (ll j = 0; j < 40; j++)
            dp[i][j] = -1;
    for (ll i = 1; i < 40; i++)
        dp[0][i] = 0, dp[i][0] = 0;
    dp[0][0]=1;
    ll ans=0;
    for(ll i=h;i<=n;i++)ans+=tree(n,i);
    cout<<ans;
}