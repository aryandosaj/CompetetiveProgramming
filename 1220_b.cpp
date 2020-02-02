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
    ll n;
    cin >> n;
    ll arr[n][n];
    ll g = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll a = sqrt((arr[0][1] * arr[0][2]) / (arr[1][2]));
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << (arr[0][i] / a) << " ";
        else
            cout << a << " ";
    }
}