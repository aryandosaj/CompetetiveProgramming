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
ll dp[1111111];
ll n;

ll rec(ll mask)
{
    ll b = __builtin_popcountll(mask);
    if (dp[mask] != -1)
        return dp[mask];
    if (b == (n))
        return 1;
    else
    {
        ll ans = 0;
        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            flag = 0;
            if ((mask & (1 << i)) == 0)
            {
                for (ll j = 0; j < n; j++)
                {
                    if ((mask & (1 << j)) != 0)
                    {
                        if (((i + 1) & (j + 1)) == (1 + i))
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (!flag)
                    ans += rec(mask | (1 << i));
            }
        }
        return dp[mask] = ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (ll i = 0; i < 1111111; i++)
        dp[i] = -1;
    cout << rec(0);
}