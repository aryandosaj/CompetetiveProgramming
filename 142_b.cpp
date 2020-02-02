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
    ll n, m;
    cin >> n >> m;
    if (min(n, m) == 1)
    {
        cout << (n * m);
        return 0;
    }
    else if (n * m == 6)
    {
        cout << "4";
        return 0;
    }
    else if (n * m < 6)
    {
        cout << n * m;
        return 0;
    }
    else if (min(n, m) == 2)
    {
        ll t = max(n, m);
        if (t == 2)
        {
            cout << "4";
            return 0;
        }
        if ((t & 1) && (((t + 1) / 2) & 1))
        {
            cout << (1 + (((t / 2) + 1) / 2) * 2) * 2;
            return 0;
        }
        else if ((t / 2) & 1)
        {
            cout << (t / 2 + 1) * 2;
            return 0;
        }
        else
            cout << (n * m / 2);
    }
    else
    {
        cout << (n * m + 1) / 2;
    }
}