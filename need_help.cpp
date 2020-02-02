#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define fr(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define rfr(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
ll fact[1010];
ll inv[1010];
ll invfact[1010];
ll ncr(ll n, ll i)
{
    return (((fact[n] * invfact[i]) % mod) * invfact[n - i]) % mod;
}
void factorial()
{
    fact[0] = 1;
    for (ll i = 1; i <= 1005; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}
void invfactorial()
{
    inv[0] = inv[1] = invfact[0] = 1;
    for (ll i = 2; i <= 1005; i++)
        inv[i] = (inv[mod % i] * (mod - mod / i)) % mod;
    for (ll i = 1; i <= 1005; i++)
        invfact[i] = (invfact[i - 1] * inv[i]) % mod;
}
ll power(ll x, ll y)
{
    ll p = mod;
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
bool comp(ll a, ll b)
{
    return a > b;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    factorial();
    invfactorial();
    // cout<<ncr(5 ,3);
    ll n, k;
    cin >> n >> k;
    ll a[n + 5], raise[101][n + 5], prefixsum[101][n + 5];
    forn(i, n)
    {
        cin >> a[i];
        raise[0][i] = 1;
        raise[1][i] = a[i];
    }
    sort(a, a + n, comp);

    forn(i, n)
    {
        // cin >> a[i];
        raise[0][i] = 1;
        raise[1][i] = a[i];
    }
    
    
    
    for (int i = 2; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            raise[i][j] = raise[i - 1][j] * a[j];
        }
    }
    // cout<<raise[5][2]<<"==";
    for (int i = 0; i <= k; i++)
    {
        ll sum = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            sum = (sum + raise[i][j]) % mod;
            prefixsum[i][j] = sum;
        }
    }
    ll res = 0,sign=-1;
    for (int i = 0; i < n; i++)
    {
        res = (res + ((n - 1 - i) * power(a[i], k)) % mod) % mod;
        sign =-1;
        for (int j = 1; j <= k; j++)
        {
            res = res + sign*(((ncr(n, j) * power(a[i], n - j))) * (prefixsum[j][i + 1]));sign*=-1;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         res = (res + power(a[j] - a[i], k)) % mod;
    //     }
    // }
    cout << (2 * res) % mod << "\n";
    return 0;
}
