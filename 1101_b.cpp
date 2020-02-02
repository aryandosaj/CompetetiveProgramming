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
    ll n, m;
    cin >> n >> m;
    ll arr[m];
    map<ll, ll> mp;
    for (ll i = 0; i < m; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    ll x = m / n;
    ll ans = 0;
    ll c = 0;

    for (ll j = x; j > 0; j--)
    {
        /* code */

        for (auto i : mp)
        {
            c += (i.second / j);
        }
        // cout<<c<<" ";
        if (c>=n)
        {
            cout << j;
            return 0;
        }
        else
        {
            c = 0;
        }
    }
    cout << "0";
}