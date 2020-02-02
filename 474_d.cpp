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
ll dp[100005][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    ll k;
    cin >> k;
    for (ll i = 0; i < 100005; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    ll pre[100005];
    ll s1=0,s2=0;
    dp[0][0]=1;
    dp[0][1]=0;
    for (ll i = 1; i <= 100005; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1])%MAX;
        if ((i - k) >= 0)
            dp[i][1] = (dp[i - k][0] + dp[i - k][1])%MAX;
        (s1+=dp[i][0])%=MAX;
        (s2+=dp[i][1])%=MAX;
        pre[i]=(s1+s2)%MAX;
    }
    while(t--)
    {
        ll a,b;cin>>a>>b;
        cout<<(pre[b]-pre[a-1]+MAX)%MAX<<"\n";
    }
}