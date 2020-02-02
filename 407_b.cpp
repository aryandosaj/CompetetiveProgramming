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
ll p[1000 + 1];
vll graph[1001];
ll dp[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        graph[i].push_back(p[i]);
    }
    // p[0]=0;
    dp[1]=0;
    for (ll i = 2; i <= n+1; i++)
    {
        dp[i]=(2*dp[i-1]+2-dp[p[i-1]]+MAX)%MAX;
    }

    cout<<dp[n+1];
    // dp[1][1]=1;
}