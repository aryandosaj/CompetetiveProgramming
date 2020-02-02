#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll n;
ll a[300005];
ll dp[300005][3];
ll b[300005];
ll rec(ll i, ll f)
{
    if (dp[i][f] != -1)
        return dp[i][f];
    if (i == n)
        return 0;
    ll ans = 1e18;
    for (int x = 0; x < 3; x++)
    {
        if (i == 0 || a[i-1] + f  != a[i] + x )
            ans = min(ans, rec(i + 1, x) + x * b[i]);
    }
    return dp[i][f]=ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {

        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = -1, dp[i][1] = -1, dp[i][2] = -1;
        }
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        ll ans = rec(0,0);
        cout<<ans<<"\n";
    }
}