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
    ll arr[n];
    ll s = 0;
    for (ll i = 0; i < n; i++)
        cin >> arr[i], s += arr[i];
    sort(arr, arr + n);
    ll mm = *max_element(arr, arr + n);
    ll x = 0, c = 1;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] >= (c))
        {
            c++;
        }
        if(c==(mm+1)) break;
    }
    cout << s -  n -(mm-c+1);
}