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
    ll dp[100005][105];
    ll dad[100005];


#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    map<ll, ll> grp;
    ll c=0;
    dad[1] = 0;
    grp[0]++;
    for (ll i = 1; i < n; i++)
    {
        ll a;
        cin >> a;
        grp[a]++;
        
        dad[i + 1] = a;
    }

    for (ll i = 0; i < n + 1; i++)
    {
        for (ll j = 0; j < k + 1; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (ll i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][1] = 1;
    
    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < k + 1; j++)
        {
            dp[i][j] += (dp[i - 1][j - 1] * grp[i]+dp[i-1][j])%MAX;
            dp[i][j]%=MAX;
        }
    }

    cout << dp[n][k];
    
}