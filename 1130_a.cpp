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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll pos = 0, neg = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0)
            pos++;
        if (x < 0)
            neg++;
    }
    if (pos >= (n + 1) / 2)
        cout << "1";
    else if (neg >= (n + 1) / 2)
        cout << "-1";
    else
        cout << "0";
}