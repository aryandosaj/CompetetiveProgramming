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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, p;
    cin >> n >> p;
    ll d = 0;
    ll ans = MAX;
    for (ll i = 0; i < 31; i++)
    {
        ll num = n - i * p;
        if (num <= 0)
            continue;
        ll b = __builtin_popcount(num);
        if (b <= i && num >= i)
        {
            cout << i;
            return 0;
        }
    }

    cout << "-1\n";
}