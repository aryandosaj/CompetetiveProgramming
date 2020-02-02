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
int n;
int arr[3005];
int dp[3005][3005][3];
int rec(int i, int mx, int c)
{

    if (i == n)
        return dp[i][mx][c] = 0;
    if (dp[i][mx][c] != -1)
        return dp[i][mx][c];
    ll ans = rec(i + 1, mx, c) % 987654319;

    if (arr[i] >= arr[mx])
        return dp[i][mx][c] = ans;
    if (c == 2)
        return dp[i][mx][c] = (ans + 1)% 987654319;
    for (int j = i + 1; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (arr[k] < arr[i] && arr[j] < arr[k] && arr[j] < arr[i])
            {
                ans = (ans + rec(k + 1, j, c + 1)) % 987654319;
            }
        }
    }
    return dp[i][mx][c] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 3005; i++)
        for (int j = 0; j < 3005; j++)
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = MAX;
    cout << rec(0, n, 0);
}