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
    ll n, k;
    cin >> n >> k;
    ll mesha[n + 1];
    ll mom[n + 1];
    ll p[n + 1];
    for (ll i = 1; i <= n; i++)
        cin >> mom[i], p[i] = i;
    for (ll i = 1; i <= n; i++)
        cin >> mesha[i];
    ll flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mesha[i] != i)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "NO";
        return 0;
    }
    int next[2][n + 1];
    for (ll i = 1; i <= n; i++)
    {
        next[0][mom[i]] = i;
        next[1][i] = mom[i];
    }
    ll ne[n + 1];
    ll move = 0;
    ll h = 0, t = 0, f = 0;
    for (ll i = 1; i <= k; i++)
    {
        f = 0;
        for (ll j = 1; j <= n; j++)
            ne[next[move][j]] = p[j];
        for (ll j = 1; j <= n; j++)
            p[j] = ne[j];
        for (ll j = 1; j <= n; j++)
        {
            if (p[j] != mesha[j])
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            h = i;
            break;
        }
    }
    move = 1;
    for (ll i = 1; i <= n; i++)
        p[i] = i;
    for (ll i = 1; i <= k; i++)
    {
        f = 0;
        for (ll j = 1; j <= n; j++)
            ne[next[move][j]] = p[j];
        for (ll j = 1; j <= n; j++)
            p[j] = ne[j];
        for (ll j = 1; j <= n; j++)
        {
            if (p[j] != mesha[j])
            {
                f = 1;
                break;
            }
        }
        if (!f)
        {
            t = i;
            break;
        }
    }
    // cout << h << " " << t;
    if (h == 0 && t == 0)
    {
        cout << "NO";
        return 0;
    }
    if (h == 1 && t == 1 && k != 1)
    {
        cout << "NO";
        return 0;
    }
    if (h > k && t > k)
    {
        cout << "NO";
        return 0;
    }
    if((h==0||t==0)&&(h+t<k)&&((k-h+t)&1))
    {
        cout << "NO";
        return 0;
    }
    if (((k - t) & 1) && ((k - h) & 1))
        cout << "NO";
    else
        cout << "YES";
}