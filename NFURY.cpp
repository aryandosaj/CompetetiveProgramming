#include <bits/stdc++.h>
using namespace std;
int findans(int *arr, int sum, int i, int **dp)
{
    // cout << sum << " " << i << "\n";
    if (i > 35)
    {
        return 999999;
    }

    if (sum == 0)
    {
        return 0;
    }

    if (sum < 0)
    {
        return 999999;
    }

    if (dp[sum][i] != -1)
    {
        return dp[sum][i];
    }

    int op1 = 1 + findans(arr, sum - arr[i], i, dp);
    int op2 = findans(arr, sum, i + 1, dp);

    dp[sum][i] = min(op1, op2);
    return dp[sum][i];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int *arr = new int[41];
    for (int i = 1; i <= 40; i++)
    {
        arr[i] = i * i;
    }

    int **dp = new int *[1001];
    for (int i = 0; i <= 1000; i++)
    {
        dp[i] = new int[51];
        for (int j = 0; j <= 50; j++)
        {
            dp[i][j] = -1;
        }
    }
    while (t--)
    {

        int n;
        cin >> n;
        int ans = findans(arr, n, 1, dp);
        cout << ans << "\n";
    }

    return 0;
}