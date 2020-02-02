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
    map<ll, ll> mp;
    ll a1[n][m];
    ll a2[n][m];
    ll f[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            f[i][j] = 0;
            ll x;
            cin >> x;
            a1[i][j] = x;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            a2[i][j] = x;
        }
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = 0; j < m - 1; j++)
        {
            if (a1[i][j] >= a1[i + 1][j])
            {
                swap(a1[i + 1][j], a2[i + 1][j]);
                if ((a1[i][j] >= a1[i + 1][j]) || (a2[i][j] >= a2[i + 1][j]))
                {
                    cout << "Impossible";
                    return 0;
                }
            }
            else
            {
                if (a2[i][j] >= a2[i + 1][j])
                {
                    swap(a1[i + 1][j], a2[i + 1][j]);
                    if ((a2[i][j] >= a2[i + 1][j]) || (a1[i][j] >= a1[i + 1][j]))
                    {
                        cout << "Impossible";
                        return 0;
                    }
                }
            }
            if (a1[i][j] >= a1[i][j + 1])
            {
                swap(a1[i][j + 1], a2[i][j + 1]);
                if ((a1[i][j] >= a1[i][j + 1]) || (a2[i][j] >= a2[i][j + 1]))
                {
                    cout << "Impossible";
                    return 0;
                }
            }
            else
            {
                if (a2[i][j] >= a2[i][j + 1])
                {
                    swap(a1[i][j + 1], a2[i][j + 1]);
                    if ((a2[i][j] >= a2[i][j + 1]) || (a1[i][j] >= a1[i][j + 1]))
                    {
                        cout << "Impossible";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Possible";
}