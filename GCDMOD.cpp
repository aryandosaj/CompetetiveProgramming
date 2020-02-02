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
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; 
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        a = (a * 2) % mod;
 
        b /= 2;
    }
 
    return res % mod;
}
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c = mulmod(a,c,mod); c %= mod;
        b /= 2;
        a = mulmod(a,a,mod);
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
// #define MAX 1000000000100011
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll dif = a - b;
        if(dif==0)
        {
            cout<<(mulmod(2,power(a,n,MAX),MAX))<<"\n";
        }
        else
        
        cout << ((gcd(((power(a, n, dif) + power(b, n, dif))), dif)) % MAX) << "\n";
    }
}
