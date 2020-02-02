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
ll arr[101];
ll dp[101][101];
ll n;
ll sum[101];
ll fun(ll l, ll r)
{
    // cout<<l<<" "<<r<<"\n";
    if (l >= r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    ll smoke = 1e16;

    for (ll i = l; i < r; i++)
    {
        ll x = fun(l, i) + fun(i + 1, r) + ((sum[i] - sum[l-1] + 100) % 100)* ((sum[r] - sum[i] + 100) % 100);
        smoke = min(smoke, x);
    }
    return dp[l][r] = smoke;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (cin >> n)
    {
        
        sum[0] = 0;
        for (int i = 0; i <= 100; i++)
        {
            sum[i]=0;
            for (int j = 0; j <= 100; j++)
                dp[i][j] = -1;
        }
        
        for (int i = 1; i <= n; i++)
            cin >> arr[i], sum[i] = sum[i - 1] + arr[i];
        cout << fun(1, n) << "\n";
    }
}