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
ll dp[101][10001];
vll bogie[101];
vll pre[101];
vll post[101];
vll best[101];
ll rec(ll n, ll k)
{
    if (k <= 0)
        return 0;
    if (n <= -1)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];
    ll ans = 0;
    for (ll i = 0; i <= min((ll)bogie[n].size(), k); i++)
    {
        ans = max(ans, best[n][i] + rec(n - 1, k - i));
    }
    return dp[n][k] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 0; i < 101; i++)
        for (ll j = 0; j < 10001; j++)
            dp[i][j] = -1;
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        ll pr = 0;
        pre[i].push_back(0);
        post[i].push_back(0);
        for (ll j = 0; j < p; j++)
        {
            ll b = 0;
            cin >> b;
            pr += b;
            bogie[i].push_back(b);
            pre[i].push_back(pr);
        }
        pr = 0;
        for (ll j = p - 1; j >= 0; j--)
        {
            pr += bogie[i][j];
            post[i].push_back(pr);
        }
        for (ll j = 0; j <= p; j++)
        {
            ll mm = 0;
            for (ll k = 0; k <= j; k++)
            {
                mm = max(pre[i][k] + post[i][j - k], mm);
            }
            best[i].push_back(mm);
        }
    }
    cout << rec(n - 1, m) << "\n";
}