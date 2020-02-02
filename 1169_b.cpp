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
    ll a[m + 1], b[m + 1];
    for (ll i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    {
        ll x = a[0];
        ll i = 1;
        while (((x == a[i]) || (x == b[i])) && (i < m))
            i++;
        if (i == m)
        {
            cout << "YES";
            return 0;
        }
        ll ii = i;
        ll y = a[i];
        while ((i < m) && ((a[i] == x) || (a[i] == y) || (b[i] == x) || (b[i] == y)))
            i++;
        if (i == m)
        {
            cout << "YES";
            return 0;
        }
        else
        {
            i = ii;
            y = b[i];
            while ((i < m) && ((a[i] == x) || (a[i] == y) || (b[i] == x) || (b[i] == y)))
                i++;
            if (i == m)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    {
        ll x = b[0];
        ll i = 1;
        while (((x == a[i]) || (x == b[i])) && (i < m))
            i++;
        if (i == m)
        {
            cout << "YES";
            return 0;
        }
        ll ii = i;
        ll y = a[i];
        while ((i < m) && ((a[i] == x) || (a[i] == y) || (b[i] == x) || (b[i] == y)))
            i++;
        if (i == m)
        {
            cout << "YES";
            return 0;
        }
        else
        {
            i = ii;
            y = b[i];
            while ((i < m) && ((a[i] == x) || (a[i] == y) || (b[i] == x) || (b[i] == y)))
                i++;
            if (i == m)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}