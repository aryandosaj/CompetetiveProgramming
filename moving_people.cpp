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
    ll n, m, q;
    cin >> n >> m >> q;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int r1, r2, c1, c2;
    r1 = 0, r2 = n - 1, c1 = 0, c2 = m - 1;
    int x1, x2, y1, y2;
    x1 = 0, y1 = 0, x2 = n - 1, y2 = m - 1;
    int pre[n][m];
    for (int i = r1; i <= r2; i++)
        pre[i][0] = s[i][0] - '0';
    for (int i = r1; i <= r2; i++)
        for (int j = 1; j <= c2; j++)
            pre[i][j] = pre[i][j - 1] + s[i][j] - '0';
    int f=0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            if (x > 0)
            {
                if (x1 - x <= 0)
                {
                    c1 = c1 - (x1 - x);
                    x1 = 0;
                    x2 = x2 - x;
                }
                else
                {
                    x1 = x1 - x;
                    x2 = x2 - x;
                }
            }
            else
            {
                if (x2 - x >= n)
                {
                    int out = x2 - x - (n - 1);
                    x2 = n - 1;
                    x1 = x1 - x;
                    c2 = c2 - out;
                }
                else
                {
                    x1 -= x;
                    x2 -= x;
                }
            }
            if (y > 0)
            {
                if (y1 - y <= 0)
                {
                    r1 = r1 - (y1 - y);
                    y1 = 0;
                    y2 = y2 - y;
                }
                else
                {
                    y1 = y1 - y;
                    y2 = y2 - y;
                }
            }
            else
            {
                if (y2 - y >= m)
                {
                    int out = y2 - y - (m - 1);
                    y2 = m - 1;
                    y1 = y1 - y;
                    r2 = r2 - out;
                }
                else
                {
                    y1 -= y;
                    y2 -= y;
                }
            }
            if(r1>r2)
            f=1;
            if(c1>c2)
            f=1;
        }
        else
        {
            if(f){cout<<"0\n";continue;}
            int ans = 0;
            for (int i = r1; i <= r2; i++)
            {
                if (c1)
                    ans += pre[i][c2] - pre[i][c1 - 1];
                else
                    ans += pre[i][c2];
            }
            // cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<" "<<ans<<"\n";
            cout << ans << "\n";
        }
    }
}