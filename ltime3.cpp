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
ll p[100005];
ll fac[100005];
ll arr[100005];
ll ans[100005];
ll inv[100005];
ll ncra[2001][2001];
// ll ncr(ll n, ll r)
// {
//     if (r > n)
//         return 1;
//     ll d = (fac[r] * fac[n - r]) % MAX;
//     return (fac[n] * power(d, MAX - 2, MAX)) % MAX;
// }
ll ncr(int n, int k)
{
    if (ncra[n][k] != -1)
        return ncra[n][k];
    if (k == 0 || k == n)
        return 1;

    return ncra[n][k] = (ncr(n - 1, k - 1) +
                        ncr(n - 1, k))%MAX;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p[0] = 1;
    fac[0] = 1;
    for (int i = 1; i < 100005; i++)
    {
        p[i] = (p[i - 1] + p[i - 1]) % MAX;
        fac[i] = (fac[i - 1] * i) % MAX;
    }
    for (int i = 0; i < 2001; i++)
        for (int j = 0; j < 2001; j++)
            ncra[i][j] = -1;

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
        {
            ans[i] = 0;
            for (int j = i; j <= n; j++)
            {
                ans[i] = (ans[i] + (((p[n - j] * ncr(j - 1,i - 1)) % MAX) * arr[j]) % MAX) % MAX;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}