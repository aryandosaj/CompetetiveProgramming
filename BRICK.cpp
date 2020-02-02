#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
ll dp[100001][1001];
ll rec(ll n, ll k)
{   
    if(n>100000)
    return (rec(n-1,k)+rec(n-2,k-1)+rec(n-1,k-1))%MAX;
    if (dp[n][k] != -1)
        return dp[n][k];
    if (n == k)
    {
        return dp[n][k] = 2;
    }
    else if (k == 0)
        return dp[n][k] = 1;
    else if (k == 1)
        return dp[n][k] = 2 * n;
    else
    {
        dp[n][k]=(rec(n-1,k)+rec(n-2,k-1)+rec(n-1,k-1))%MAX;
        return dp[n][k];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i =0;i<100001;i++)
    {
        
        for(ll j = 0; j < 1001; j++)
        {
            dp[i][j]=-1;
        }
        
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout<<rec(n,k)<<"\n";
    }
}