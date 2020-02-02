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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll vil[n];
        ll e[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> vil[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> e[i];
        }
        sort(vil, vil + n);
        sort(e, e + n);
        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            if (vil[i] >= e[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            cout << "LOSE\n";
        }
        else
            cout << "WIN\n";
    }
}