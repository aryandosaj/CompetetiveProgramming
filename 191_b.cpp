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
struct dt
{
    ll a, i;
};
bool comp(dt a, dt b)
{
    if (a.a == b.a)
        return a.i > b.i;
    else
        return a.a > b.a;
}
bool comp2(dt a, dt b)
{
    if (a.a == b.a)
        return a.i < b.i;
    else
        return a.a < b.a;
}
int vis[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, b;
    cin >> n >> k >> b;
    dt a[n - 1];
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i != n - 1)
        {
            a[i].i = i;
            a[i].a = arr[i];
        }
    }
    sort(a, a + n - 1, comp);
    ll mm = 0;
    for (ll i = 0; i < k; i++)
    {
        mm += a[i].a;
        vis[a[i].i] = 1;
    }
    ll ans = -1;
    if (b >= mm)
        cout << n;
    else
    {
        for (ll i = 0; i < n; i++)
        {
            if (vis[i])
            {
                if (b - (mm - arr[i]) < arr[i])
                {
                    cout << i + 1;
                    return 0;
                }
            }
            else
            {
                if (b - (mm - a[k-1].a) < arr[i])
                {
                    cout << i + 1;
                    return 0;
                }
            }
            
        }
    }
}