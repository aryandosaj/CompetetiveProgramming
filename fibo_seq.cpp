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
#define N 5
ll a[N][N];
ll c[N][N];
ll res[N][N];
void multiply1()
{
    ll i, j, k;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += a[i][k] *
                             c[k][j],
                    res[i][j] %= MAX;
        }
    }
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            c[i][j] = res[i][j];
}
void multiply2()
{
    ll i, j, k;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += a[i][k] *
                             a[k][j],
                    res[i][j] %= MAX;
        }
    }
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = res[i][j];
}

void matpow(ll b)
{
    while (b > 0)
    {
        if (b % 2)
            multiply1();
        b /= 2;
        multiply2();
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        for (ll i = 0; i < N; i++)
        {
            for (ll j = 0; j < N; j++)
            {
                c[i][j] = 0;
                a[i][j] = 0;
                res[i][j]=0;
            }
        }
        ll n, aa, bb, cc, dd, ee;
        cin >> aa >> bb >> cc >> dd >> ee >> n;
        aa = aa%MAX;
        bb = bb%MAX;
        cc = cc%MAX;
        dd = dd%MAX;
        ee = ee%MAX;
        a[0][0] = aa;
        a[0][1] = bb;
        a[0][2] = cc;
        a[0][3] = dd;
        a[0][4] = 1;

        a[1][0] = 1;
        a[2][1] = 1;
        a[3][2] = 1;
        a[4][4] = 1;

        c[0][0] = 1;
        c[1][1] = 1;
        c[2][2] = 1;
        c[3][3] = 1;
        c[4][4] = 1;
        matpow(n - 4);

        ll arr[5];
        arr[0] = 3;
        arr[1] = 2;
        arr[2] = 1;
        arr[3] = 0;
        arr[4] = ee;
        ll ans = 0;
        for (ll i = 0; i < N; i++)
        {
            ans = (ans + c[0][i] * arr[i]) % MAX;
        }
        cout << ans<<"\n";
    }
}