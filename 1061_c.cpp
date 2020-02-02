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
ll dp[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < 1000005; i++)
        dp[i] = 0;
    dp[0]=1;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (ll j = 1; j * j <= arr[i]; j++)
            if (arr[i] % j == 0)
                (dp[arr[i] / j] += dp[arr[i] / j - 1])%=MAX;
        for (ll j = sqrt(arr[i]); j >= 1; j--)
            if ((arr[i] % j == 0) && (arr[i] != j * j))
                (dp[j] += dp[j - 1])%=MAX;
    }
    ll ans=0;
    for (ll i = 1; i < 1000005; i++)(ans+=dp[i])%=MAX;
    cout<<ans;

}