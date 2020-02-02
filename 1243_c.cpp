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
bool prime[1000006];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 2; i < 1000006; i++)
    {
        if (prime[i] == 0)
        {
            for (ll j = 2 * i; j < 1000006; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    int c = 0;
    vector<ll> v;
    for (ll i = 2; i * i <= n; i++)
    {
        if(c>=2)break;
        if (n % i == 0)
        {
            if (prime[i] == 0)
            {
                c++;
                v.push_back(i);

                ll num = n / i;
                while (num % i == 0)
                    num /= i;
                if (num > 1)
                    c++;
                else
                    break;
                    
            }
        }
    }

    if (c >= 2)
    {
        cout << 1 << "\n";
    }
    else
    {
        if (c)
            cout << v[0] << "\n";
        else
            cout << n << "\n";
    }
}