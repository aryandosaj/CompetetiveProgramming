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
bool dp[1005][1005];
bool up(char a)
{
    if ((a <= 'Z') && ('A' <= a))
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        a = 'A' + a;
        b = 'A' + b;
        for (ll i = 0; i < 1005; i++)
        {
            for (ll j = 0; j < 1005; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (ll i = 0; i < a.length(); i++)
        {
            for (ll j = 0; j < b.length(); j++)
            {
                if (dp[i][j])
                {
                    if (up(a[i + 1]))
                    {
                        // cout<<"here";
                        if (a[i + 1] == b[j + 1])
                            dp[i + 1][j + 1] = 1;
                    }
                    else
                    {
                        dp[i + 1][j] = 1;
                        if ((a[i + 1] - 32) == b[j + 1])
                            dp[i + 1][j + 1] = 1;
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
        }
        if (dp[a.length()-1][b.length()-1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}