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
ld dp[102][102][102];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll r, p, s;
    ll r1, p1, s1;
    cin >> r >> s >> p;
    r1 = r;
    p1 = p;
    s1 = s;
    dp[r][p][s] = 1;
    for (int i = 0; i < 102; i++)
    {
        for (int j = 0; j < 102; j++)
        {
            for (int k = 0; k < 102; k++)
                if ((i == r) && (j == p) && (k == s))
                    dp[i][j][k] = 1;
                else
                    dp[i][j][k] = 0;
        }
    }
    for (r=r1; r >= 0; r--)
    {
        for (p=p1; p >= 0; p--)
        {
            for (s=s1; s >= 0; s--)
            {
                // if((r==r1)&&(p==p1)&&(s==s1))continue;
                if((s!=s1)&&(!((r==0)&&(p==0))))
                dp[r][p][s] += ((ld)(r * (s+1)) / (ld)(r * (s+1) + p * r + p * (s+1)))*dp[r][p][s+1] ;
                if((p!=p1)&&(!((r==0)&&(s==0))))
                dp[r][p][s] += ((ld)(s * (p+1)) / (ld)(r * s + (p+1) * r + (p+1) * s)) *dp[r][p+1][s];
                if((r!=r1)&&(!((s==0)&&(p==0))))
                dp[r][p][s] += ((ld)((r+1) * p) / (ld)((r+1) * s + p * (r+1) + p * s)) *dp[r+1][p][s];
                // cout<<r<<" "<<p<<" " <<s<<"\n";
                // cout<<dp[r][p][s]<<"\n";
            }
        }
    }
    ld rr = 0;
    ld pp = 0;
    ld ss = 0;
    for (int i = 1; i <= r1; i++)
        rr += dp[i][0][0];
    for (int i = 1; i <= p1; i++)
        pp += dp[0][i][0];
    for (int i = 1; i <= s1; i++)
        ss += dp[0][0][i];
    cout<<setprecision(15);
    cout<< rr << " " << ss << " " << pp;
}