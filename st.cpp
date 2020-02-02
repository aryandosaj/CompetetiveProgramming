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
    ll n, m;
    cin >> n >> m;
    string s[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    ll ans = 0;
    for (ll i = 1; i < n - 1; i++)
    {
        for (ll j = 1; j < m; j++)
        {
            if (s[i][j] == '*')
            {
                if ((s[i][j - 1] == '*') && (s[i][j + 1] == '*') && (s[i - 1][j] == '*') && (s[i + 1][j] == '*'))
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}