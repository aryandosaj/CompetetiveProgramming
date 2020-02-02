#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
bool isprime(ll n)
{
    ll flag = 0;
    ll root = sqrt(n);
    for (ll i = 2; i <= root; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            return 0;
        }
    }
    return 1;
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
bool isplay(ll n)
{
    ll f = n % 10;
    n = n / 10;
    if ((f == 2) || (f == 3) || (f == 5) || (f == 7))
    {
        f = n % 10;
        n = n / 10;
        if ((f == 2) || (f == 3) || (f == 5) || (f == 7))
        {
            f = n % 10;
            n = n / 10;
            if ((f == 1) || (f == 4) || (f == 6) || (f == 8) || (f == 9))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // //code start here
    // cout<<isplay(123);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k, p = 0, np = 0;

        cin >> n >> m >> k;
        if (n <= 3)
        {
            ll c=0;

            for (ll i = power(10, n-1, MAX); i < power(10, n, MAX); i++)
            {
                if ((i % m == k) && (isplay(i)))
                {
                    c++;
                }
            }
            cout << c<<"\n";
            continue;

        }
        for (ll i = 1; i <= n; i++)
        {
            if (isprime(i))
                p++;
            else
                np++;
        }
        p -= 2;
        np--;
        cout << "p=" << p << "np=" << np << "\n";
        ll c;
        // ll x=min(1000,power(10,n,MAX));
        for (ll i = k; i < 1000; i++)
        {
            if ((i % m == k) && (isplay(i)))
            {
                c++;
            }
        }
        cout << c << "\n";
        ll ans = (((power(4, p, MAX) * power(5, np, MAX)) % MAX) * c) % MAX;
        cout << ans;
    }
}