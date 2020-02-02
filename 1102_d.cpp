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
    string s;
    cin >> s;
    ll w = n / 3;
    ll p = 0, q = 0, r = 0;
    ll ep = 0, eq = 0, er = 0;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] - 48 == 0)
            p++;
        if (s[i] - 48 == 1)
            q++;
        if (s[i] - 48 == 2)
            r++;
    }
    if ((p == q) && (r == q))
    {
        cout << s;
        return 0;
    }
    ep = p - w;
    eq = q - w;
    er = r - w;
    // cout<<ep<<eq<<er;

    if ((ep >= 0) && (eq >= 0))
    {
        ll i = n-1;
        while (ep > 0)
        {
            if (s[i] == '0')
            {
                s[i] = '2';
                ep--;
            }
            i--;
        }
        i=n-1;
        while (eq > 0)
        {
            if (s[i] == '1')
            {
                s[i] = '2';
                eq--;
            }
            i--;
        }
    }
    else if ((ep >= 0) && (eq <= 0) && (er >= 0))
    {
        ll i = n-1;
        while (ep > 0)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                ep--;
            }
            i--;
        }
        i=0;
        while (er > 0)
        {
            if (s[i] == '2')
            {
                s[i] = '1';
                er--;
            }
            i++;
        }
    }
    else if ((ep <= 0) && (eq >= 0) && (er >= 0))
    {
        ll i = 0;
        while (eq > 0)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
                eq--;
            }
            i++;
        }
        i=0;
        while (er > 0)
        {
            if (s[i] == '2')
            {
                s[i] = '0';
                er--;
            }
            i++;
        }
    }
    else if ((ep <= 0) && (eq <= 0) && (er >= 0))
    {
        ll i = 0;
        while (ep < 0)
        {
            if (s[i] == '2')
            {
                s[i] = '0';
                ep++;
            }
            i++;
        }
        i=0;
        while (eq < 0)
        {
            if (s[i] == '2')
            {
                s[i] = '1';
                eq++;
            }
            i++;
        }
    }
    else if ((ep <= 0) && (eq >= 0) && (er <= 0))
    {
        ll i = 0;
        while (ep < 0)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
                ep++;
            }
            i++;
        }
        i=n-1;
        while (er < 0)
        {
            if (s[i] == '1')
            {
                s[i] = '2';
                er++;
            }
            i--;
        }
    }
    else if ((ep >= 0) && (eq <= 0) && (er <= 0))
    {
        ll i = n-1;
        while (er < 0)
        {
            if (s[i] == '0')
            {
                s[i] = '2';
                er++;
            }
            i--;
        }
        i=n-1;
        while (eq < 0)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                eq++;
            }
            i--;
        }
        
        
    }
    cout<<s;

}