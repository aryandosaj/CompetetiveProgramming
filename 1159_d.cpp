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
    ll k = n - m;
    k /= 2;k++;
    vll v;
    for (ll i = 1; i <= n; i++)
    {
        if ( ((i % k) == 0))
            v.push_back(1);
        else
            v.push_back(0); 
    }   
    for (auto i : v)
        cout << i;
}