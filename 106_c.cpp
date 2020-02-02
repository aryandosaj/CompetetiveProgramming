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
    vll c, d, b, a;
    cin >> n >> m;
    ll c0, d0;
    cin >> c0 >> d0;
    c.push_back(0);
    d.push_back(0);
    a.push_back(0);
    b.push_back(0);
    c.push_back(c0);
    d.push_back(d0);
    a.push_back(1);
    b.push_back(0);
    for (ll i = 0; i < m; i++)
    {
        ll aa, bb, cc, dd;
        cin >> aa >> bb >> cc >> dd;
        a.push_back(aa);
        b.push_back(bb);
        c.push_back(cc);
        d.push_back(dd);
    }
    ll dp[m + 3][n + 3];

    for (ll i = 0; i < n + 3; i++)
    {
        dp[0][i] = 0;
    }

    for (ll i = 0; i < m + 3; i++)
    {
        dp[i][0] = 0;
    }

    for (ll i = 1; i <= m + 1; i++)
    {

        for (ll j = 1; j <= n; j++)
        {
            ll dou = j;
            ll stuff = a[i];
            ll pro = dp[i - 1][dou];
            ll no_of_stuff = 0;
            while ((dou > 0) && (stuff > 0))
            {
                dou -= c[i];
                stuff -= b[i];
                if ((dou >= 0) && (stuff >= 0))
                {
                    no_of_stuff++;
                    pro = max(pro, no_of_stuff * d[i] + dp[i - 1][dou]);
                    // if((i==2)&&(j==9))
                    //  cout<<dp[i - 1][dou]<<"-";
                }
            }
            dp[i][j] = max(pro, dp[i-1][j]);
            // cout << dp[i][j] << "\t";
        }
        // cout << "\n";
    }
    cout << dp[m + 1][n];
}