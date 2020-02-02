#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
double dp[201][201][201];
ll c[201];
double p[201];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, l, kk;
    cin >> n >> l >> kk;
    
    for(ll i=1;i<=n;i++)
    {
        cin>>p[i];p[i]/=100;
    } 
    for(ll i=1;i<=n;i++)
    {
        cin>>c[i];c[i]++;
    }
    dp[0][0][kk]=1;
    // dp[0][0][0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=i;j++)
        {
            for(ll k=0;k<=200;k++)
            {
                dp[i][j+1][min(k+c[i],(ll)200)] += dp[i-1][j][k]*p[i];
                dp[i][j][k] += dp[i-1][j][k]*(1-p[i]);
            }
        }
    }
    double ans=0;
    for(ll i = l;i<=200;i++)
    {
        for(ll m = i;m<=200;m++)
        {
            ans+=dp[n][i][m];
        }
    }
    cout<<setprecision(12)<<ans;


    
}