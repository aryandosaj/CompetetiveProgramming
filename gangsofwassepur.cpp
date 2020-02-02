#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll fact[1000006];
ll ncr(ll n, ll r)
{
    return (((fact[n] * power(fact[r], MAX - 2, MAX)) % MAX) * power(fact[n - r], MAX - 2, MAX)) % MAX;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i)%MAX;
    ll ans = ncr(n, k);
    ll a = 0;
    for (int i = 2; i <= k; i++)
    {
        if (i % 2 == 0)
            a = (a + (fact[k] * power(fact[i], MAX - 2, MAX)) % MAX) % MAX;
        else
            a = (a - (fact[k] * power(fact[i], MAX - 2, MAX)) % MAX + MAX) % MAX;
    }
    // cout<<ans<<" "<<a<<"\n";
    cout<<(ans*a)%MAX;
}