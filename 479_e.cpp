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
ll pre[5001][5001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, a, b, k;
    cin>>n>>a>>b>>k;
    ll temp[n+1];
    for (ll i = 1; i <= n; i++)
    {
        if (i != b)
            temp[i] = 1;
        else
            temp[i] = 0;
        pre[i][0] = temp[i] + pre[i - 1][0];
    }
    
    for(ll i=1;i<=k;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(j<b)
            {
                temp[j] = (pre[b-1][i-1]-pre[max((ll)0,j-(b-j))][i-1]-temp[j]+MAX+MAX)%MAX;
            }
            else if(j>b)
            {
                temp[j] = (pre[min(n,j+(j-b)-1)][i-1] - pre[b][i-1] - temp[j]+MAX+MAX)%MAX;
            }
            // cout<<dp[j][i]<<" ";
        }
        for(ll j=1;j<=n;j++)
        {
            pre[j][i] = (pre[j-1][i]+temp[j])%MAX;
        }
        // cout<<"\n";
    }
    cout<<temp[a];
}