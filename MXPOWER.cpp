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
ll arr[105][105];
ll up[105][105];
ll down[105][105];
ll n;
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
        cin >> n;
        for (int i = 1; i <= 104; i++)
        {
            for (int j = 1; j <= 104; j++)
            {
                up[i][j]=0;
                down[i][j]=0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
                down[i][j] += down[i - 1][j - 1] + arr[i][j];
            }
        }

        for (int i = n; i > 0; i--)
            for (int j = 1; j <= n; j++)
                up[i][j] += up[i + 1][j - 1] + arr[i][j];
        ll ans = -1e10;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ll s = arr[i][j];
                ll c = 1;
                ans = max(ans, s);
                while (i + c <= n && j + c <= n && i - c > 0 && j - c > 0)
                {

                    s += up[i - c][j] - up[i + 1][j - c - 1];
                    s += down[i][j + c] - down[i - c - 1][j - 1];
                    s += up[i][j + c] - up[i + c + 1][j - 1];
                    s += down[i + c][j] - down[i - 1][j - c - 1];
                    s -= arr[i + c][j] + arr[i][j + c] + arr[i - c][j] + arr[i][j - c];
                    c++;
                    
                    ans = max(ans, s);
                }
            }
        }
        cout << ans << "\n";
    }
}