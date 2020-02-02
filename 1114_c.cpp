#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, b;
    cin >> n >> b;
    vll primes;
    unordered_map<ll, ll> mp1;
    unordered_map<ll, ll> mp;
    if (b % 2 == 0)
        primes.push_back(2);
    while (b % 2 == 0)
        b /= 2, mp1[2]++;

    for (ll i = 3; i <= sqrt(b); i += 2)
    {
        if (b % i == 0)
            primes.push_back(i);
        while (b % i == 0)
            b /= i, mp1[i]++;
    }
    if (b > 2)
        primes.push_back(b), mp1[b]++;

    for (ll i = 0; i < primes.size(); i++)
    {
        ll cur = primes[i];
        ll total = 0;
        while (cur <= n)
        {
            total += (n / cur);
            if ((n / cur) < primes[i])
                break;
            cur = cur * primes[i];
        }
        mp[primes[i]] = total;
    }
    ll ans = mp[primes[0]] / mp1[primes[0]];
    for (ll i = 0; i < primes.size(); i++)
    {
        ans = min(ans, mp[primes[i]] / mp1[primes[i]]);
    }
    cout << ans;
}
