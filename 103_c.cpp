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
    ll n, m, q;
    cin >> n >> m >> q;
    ll t = (n - m) - (m - 1), x;
    ll dot = n - m;
    
    if (t > 0)
    {
        if (t & 1)
            x = t;
        else
            x = t + 1;
    }
    else
        x = 1;
    ll ind;
    if (dot < m)
    {
        ind = 2*dot;
    }
    while (q--)
    {
        ll a;
        cin >> a;
        if(m==1)
        {
            if(a==n)cout<<'X';else cout<<'.';continue;
        }
        if (dot < m)
        {
            if(a<ind)
            {
                if(a%2==0)cout<<'X';else cout<<'.';
            }
            else cout<<'X';
        }
        else
        {
            if (a <= x)
                cout << '.';
            else
            {
                if (t % 2 == 0)
                {
                    if (a == n)
                        {cout << 'X';
                    continue;}
                }
                if ((a - x) & 1)
                {
                    cout << 'X';
                }
                else
                {
                    cout << '.';
                }
            }
        }
    }
}