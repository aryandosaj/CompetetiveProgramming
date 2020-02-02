#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
int main()
{
    ll A=5;
    ll mod = 1e9+7;
    ll p = ((power(3,A,mod)+3*(ll)pow(-1,A)+mod)*power(4,mod-2,mod)) % mod;
    ll q = power(3,A,mod);
    cout<< (p*power(q,mod-2,mod))%mod;
}
