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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> m >> n;
        ll w[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> w[i][j];
            }
        }
        ll ans = -MAX;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                ll sum = w[i][j];
                ll d = 1;
                while (1)
                {
                    if ((i + d) >= m || (i - d) < 0 || (j + d) >= n || (j - d) < 0)
                        break;
                    sum += w[i + d][j + d] + w[i + d][j - d] + w[i - d][j + d] + w[i - d][j - d];
                    ans = max(ans, sum);
                    d++;
                }
            }
        }
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                ll sum = w[i][j] + w[i + 1][j] + w[i][j + 1] + w[i + 1][j + 1];
                ans = max(ans, sum);
                ll d = 1;
                while (1)
                {
                    if ((i - d) < 0 || (j - d) < 0)
                        break;
                    if ((i - d) < 0 || (j + 1 + d) >= n)
                        break;
                    if ((i + 1 + d) >= m || (j - d) < 0)
                        break;
                    if ((i + 1 + d) >= m || (j + 1 + d) >= n)
                        break;
                    sum += w[i + 1 + d][j + 1 + d] + w[i + 1 + d][j - d] + w[i - d][j + 1 + d] + w[i - d][j - d];
                    ans = max(ans, sum);
                    d++;
                }
            }
        }

        cout << ans << "\n";
    }
}