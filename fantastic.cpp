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
    ll arr[n];
    ll cur_xor = 0;
    vll v;
    v.push_back(0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (ll i = 0; i < n; i++)
    {
        if (i & 1)
        {
            v.push_back(cur_xor);
            cur_xor ^= cur_xor;
        }
        else
        {
            v.push_back(cur_xor ^ arr[i]);
            cur_xor ^= arr[i];
        }
    }

    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}