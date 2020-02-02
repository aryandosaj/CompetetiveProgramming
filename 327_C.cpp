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
#define MAX 1000000007
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
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}
ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    string ss, s;
    ll k;
    cin >> s >> k;

    ll l = s.length() * k;
    ll ans = 0;
    vll r;
    ll n = s.length();

    reverse(s.begin(), s.end());
    // cout<<ss;

    for (ll i = 0; i < s.length(); i++)
    {
        if ((s[i] == '0') || (s[i] == '5'))
            r.push_back(i);
    }

    for (ll j = 0; j < r.size(); j++)
    {
        // cout<<power(2, n - r[j] - 1 , MAX);
        ans += mulmod(power(2, n - r[j] - 1 , MAX),mulmod((power(2,n*k,MAX)-1),modInverse(power(2,n,MAX)-1,MAX),MAX),MAX);
        ans %= MAX;
    }

    cout << ans;
}
