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
ll floorSqrt(ll x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;

    // Staring from 1, try all numbers until
    // i*i is greater than or equal to x.
    ll i = 1, result = 1;
    while (result <= x)
    {
        i++;
        result = i * i;
    }
    return i - 1;
}
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
        ll arr[n];
        map<ll, ll> available_factors;
        map<ll, ll> prime_count;
        map<ll, map<ll, ll> > factor;
        vll v;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] % 2 == 0)
            {
                if (prime_count[2] == 0)
                {
                    v.push_back(2);
                    prime_count[2] = 1;
                }
            }
            ll temp = 0;
            while (arr[i] % 2 == 0)
            {
                temp++;
                arr[i] = arr[i] / 2;
            }
            if (temp > 0)
            {
                available_factors[2] += temp;
                factor[i][2] = temp;
            }

            for (ll j = 3; j <= floorSqrt(arr[i]) + 1; j = j + 2)
            {
                temp = 0;
                if (arr[i] % j == 0)
                {
                    if (prime_count[j] == 0)
                    {
                        v.push_back(j);
                        prime_count[j] = 1;
                    }
                }
                while (arr[i] % j == 0)
                {
                    temp++;
                    arr[i] = arr[i] / j;
                }
                if (temp > 0)
                {
                    available_factors[j] += temp;
                    factor[i][j] = temp;
                }
            }

            if (arr[i] > 2)
            {
                if (prime_count[arr[i]] == 0)
                {
                    v.push_back(arr[i]);
                    prime_count[arr[i]] = 1;
                }
                factor[i][arr[i]] = 1;
                available_factors[arr[i]]++;
            }
        }
        ll ans = 1;
        for (ll i = 0; i < v.size(); i++)
        {
            ll temp = available_factors[v[i]];
            ll fill = 1;
            if (temp < n)
                continue;
            while (temp > 0)
            {
                for (ll j = 0; j < n; j++)
                {
                    if (factor[j][v[i]] < fill)
                    {
                        temp -= 2;
                        if (temp < 0)
                            break;
                        factor[j][v[i]]++;
                    }
                    else
                        temp--;

                    if (temp < 0)
                        break;
                }
                if (temp < 0)
                    break;
                ans *= v[i];
                fill++;
            }
        }
        cout << ans << "\n";
    }
}