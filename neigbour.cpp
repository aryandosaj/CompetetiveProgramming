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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll dp[n + 1], arr[n + 1];
        vll v[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i], dp[i] = 0;
        dp[0] = max(dp[0], arr[0]);
        dp[1] = max(dp[0], arr[1]);
        if (arr[0] > 0)
        {
            dp[0] = arr[0];
            v[0].push_back(arr[0]);
        }
        if (arr[1] > dp[0])
        {
            dp[1] = arr[1];
            v[1].push_back(arr[1]);
        }
        else
        {
            dp[1] = dp[0];
            v[1] = v[0];
        }
        for (ll i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
            if (dp[i - 2] + arr[i] > dp[i - 1])
            {
                vll temp;
                temp = v[i - 2];
                temp.push_back(arr[i]);
                v[i] = temp;
            }
            else if (dp[i - 2] + arr[i] < dp[i - 1])
            {
                v[i] = v[i - 1];
            }
            else
            {
                if (arr[i] > v[i - 1][v[i - 1].size() - 1])
                {
                    vll temp;
                    temp = v[i - 2];
                    temp.push_back(arr[i]);
                    v[i] = temp;
                }
                else if (arr[i] < v[i - 1][v[i - 1].size() - 1])
                {
                    v[i] = v[i - 1];
                }
                else
                {
                    ll x = v[i - 2].size() - 1, y = v[i - 1].size() - 2;
                    while ((x >= 0 && y >= 0) && (v[i - 2][x] == v[i - 1][y]))
                    {
                        x--;
                        y--;
                    }
                    if (x == -1)
                    {
                        v[i] = v[i - 1];
                    }
                    else if (v[i - 2][x] < v[i - 1][y])
                    {
                        v[i] = v[i - 1];
                    }
                    else
                    {
                        vll temp;
                        temp = v[i - 2];
                        temp.push_back(arr[i]);
                        v[i] = temp;
                    }
                }
            }

            v[i - 2].clear();
        }
        for (ll i = v[n - 1].size() - 1; i >= 0; i--)
            cout << v[n - 1][i];
        cout << "\n";
    }
}