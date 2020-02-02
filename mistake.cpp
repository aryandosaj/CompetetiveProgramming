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
int n, t;
int arr[40];
int dp[150000][40];
int fun(int mask, int i, int last)
{
    if (i == n)
        return 0;
    if (dp[mask][last] != -1)
        return dp[mask][last];
    int sum = 10000000;
    for (int j = 0; j < n; j++)
    {
        if ((abs(last - arr[j]) <= t) && ((mask & (1 << j)) == 0))
            sum = min(sum, fun(mask | (1 << j), i + 1, arr[j]) + abs(arr[i] - arr[j]));
    }
    return dp[mask][last] = sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i <= 150000; i++)
        for (int j = 0; j < 40; j++)
            dp[i][j] = -1;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mask = 0;
    int sum = 10000000;
    for (int j = 0; j < n; j++)
        sum = min(sum, fun(mask | (1 << j), 1, arr[j]) + abs(arr[0] - arr[j]));
    cout << sum;
}