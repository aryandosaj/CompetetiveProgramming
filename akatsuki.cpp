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
ll dp[1111111];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ax[n], ay[n], lx[n], ly[n];
    for (ll i = 0; i < n; i++)
        cin >> ax[i] >> ay[i];
    for (ll i = 0; i < n; i++)
        cin >> lx[i] >> ly[i];
    for (ll mask = 0; mask < pow(2, n); mask++)
        dp[mask]=MAX;
    dp[0]=0;
    for (ll mask = 0; mask < pow(2, n); mask++)
    {
        ll b = __builtin_popcountll(mask);
        for(ll j=0;j<n;j++)
        {

            if((mask&(1<<j))==0)
            {
                dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]+abs(ax[b]-lx[j])+abs(ay[b]-ly[j]));
            }
        }
    }
    cout<<dp[(ll)pow(2,n)-1];
}