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

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll k = 1;
    ll j = 0;
    ll flag = 0;
    ll temp = k;
    for (ll i = 0; i < n-1; i++)
    {
        if (!(arr[i + 1] <= (2 * arr[i])))
        {
            temp = 1;
        }
        else
        {
            temp++;
            k = max(temp, k);
        }
    }
    cout<<k;
}