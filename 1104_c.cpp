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
    string s;
    cin >> s;
    ll r[1000];
    ll c[1000];
    ll o = 0, z = 0, fo = 0, fz = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            if (fo == 0)
                r[i] = 4, c[i] = 3, fo = 1;
            else
                r[i] = 4, c[i] = 1, fo = 0;
        }
        if (s[i] == '0')
        {
            if (fz == 0)
                r[i] = 1, c[i] = 1, fz = 1;
            else
                r[i] = 3, c[i] = 1, fz = 0;
        }
    }
    for(ll i=0;i<s.length();i++)
    cout<<r[i]<<" "<<c[i]<<"\n";
}