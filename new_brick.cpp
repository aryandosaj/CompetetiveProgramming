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
ll dp[10001][1001];
ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}
ll ncr(ll n, ll k)
{
    if(k>n)
    return 0;
    ll up = 1, dn = 1;
    for (ll i = 0; i < k; i++)
    {
        up *= (n - i);
        dn *= (i + 1);
        up = up % MAX;
        dn = dn % MAX;
    }
    return ((up * modInverse(dn, MAX)) % MAX);
}
int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        n++;
        for (ll i = 0; i < k; i++)
        {
            ans += (((ncr(n - k, i + 1) * ncr(k - 1, i)) % MAX) * power(2, i + 1, MAX)) % MAX;
            ans = ans%MAX;
        }
        // cout<<ncr(5,5);
        cout << ans << "\n";
    }
}