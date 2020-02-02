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
    ll arr[2 * n + 5];
    ll c = 0;
    for (ll i = 1; i <= n; i++)
        arr[i] = i;
    ll temp = 0;
    for (ll i = 2; i <= n; i++)
    {
        c++;
        temp = 0;
        for (ll j = c; j < c + n; j += i)
            swap(temp, arr[j]);
        arr[n + c] = temp;
        // for (ll i =  1; i <=  n+c; i++)
        //     cout << arr[i] << " ";cout<<"\n";
    }
    for (ll i = n ; i < 2 * n; i++)
        cout << arr[i] << " ";
        
}