#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll arr[4];
    ll s = 0;
    for (int i = 0; i < 4; i++)
        cin >> arr[i], s += arr[i];
    for (int i = 0; i < 16; i++)
    {
        ll x = 0;
        for (int j = 0; j < 4; j++)
        {
            if ((1 << j) & i)
            {
                x += arr[j];
            }
        }
        if ((x * 2) == (s))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}