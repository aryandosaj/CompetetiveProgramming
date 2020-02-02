#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int dp[1000005][21][2];
int n;
int x=0;
int f(int n, int x, int y)
{
    int tmp=(1<<x);
    if (y)
    tmp*=3;
    return n/tmp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while ((1<<x)<=n)
    x++;
    x--;
    dp[1][x][0] = 1;
    if ((1<<(x - 1)) * 3 <= n)
        dp[1][x - 1][1] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            for (int k = 1; k >= 0; k--)
            {
                dp[i + 1][j][k] = (dp[i + 1][j][k] + 1ll*dp[i][j][k] * (f(n, j, k) - i)) % MAX;
                if (j)
                    dp[i + 1][j - 1][k] = (dp[i + 1][j - 1][k] + 1ll*dp[i][j][k] * (f(n, j - 1, k) - f(n, j, k))) % MAX;
                if (k)
                    dp[i + 1][j][k - 1] = (dp[i + 1][j][k - 1] + 1ll*dp[i][j][k] * (f(n, j, k - 1) - f(n, j, k))) % MAX;
            }
        }
    }
    cout << dp[n][0][0];
}