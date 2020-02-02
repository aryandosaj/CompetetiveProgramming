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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll ans = 0;
    for (ll ii = 1; ii < (1 << n); ii++)
    {
        if (__builtin_popcount(ii) % 2 == 0)
        {
            ll a = 1;
            ll temp = ii;
            ll i = 0;
            while ((1 << i) <= temp)
            {
                if ((1 << i) & temp)
                    a = (a * arr[i]) % MAX;
                i++;
            }
            ans = (ans + a) % MAX;
        }
    }
    cout << ans % MAX;
}