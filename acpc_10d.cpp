#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100005][3];
ll dp[100005][3];

ll findans(ll n, ll i, ll j)
{
    if (i == (n - 1) && j == 1)
    {
        return arr[i][j];
    }

    if (i >= n || j >= 3 || j < 0)
    {
        return 999999999999999;
    }

    if (dp[i][j] != -1e16)
    {
        return dp[i][j];
    }

    ll op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX, op4 = INT_MAX;

    op1 = arr[i][j] + findans(n, i + 1, j - 1);
    op3 = arr[i][j] + findans(n, i + 1, j + 1);
    op2 = arr[i][j] + findans(n, i + 1, j);
    op4 = arr[i][j] + findans(n, i, j + 1);

    dp[i][j] = min(op1, min(op2, min(op3, op4)));

    return min(op1, min(op2, min(op3, op4)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll count = 0;
    while (1)
    {
        count++;
        ll n;
        cin >> n;
        if (n == 0)
        {
            break;
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
                dp[i][j] = -1e16;
            }
        }

        cout << count << ". " << findans(n, 0, 1) << "\n";
    }
    return 0;
}