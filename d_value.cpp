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
#define MAX 987654319
ll arr[3003];
ll dp[3003][2];
ll dp2[3003][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] < arr[j])
                dp[j][0] = (dp[j][0] + cnt) % MAX;
            else if (arr[j] < arr[i])
                cnt++,
                    dp[i][1] = (dp[i][1] + dp[j][0]) % MAX;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp2[j][0] = (dp2[j][0] + cnt) % MAX;
            else if (arr[i] < arr[j])
                cnt++,
                    dp2[i][1] = (dp2[i][1] + dp2[j][0]) % MAX;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + dp[i][1]*dp2[i][1])%MAX;
    }
    cout<<ans;
}