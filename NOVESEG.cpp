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
ll arr[502];
ll dp[502][502];
ll n, l, r;
ll rec(ll ind, ll f)
{
    if(f==1)
    {
        return arr[ind]/r;
    }
    if(ind<f)
    {
        return MAX;
    }
    for (int i = ind - 1; i > 0; i--)
    {
        
        if (arr[ind] >= arr[i] + r)
            dp[ind][f] = min(dp[ind][f], rec(i, f - 1) + (arr[ind] - arr[i] - r) / r);
    }
    return dp[ind][f];
}
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

        cin >> n >> l >> r;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        sort(arr + 1, arr + n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                for (int k = j + 1; k >= 1; k--)
                {
                    if (arr[j] + r <= arr[i] && j >= k - 1)
                        dp[i][k] = min(dp[i][k], dp[j][k - 1] + (arr[i] - (arr[j] + r)) / r);
                }
            }
        }
    }
}