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
ll t[400005];
ll a[100005];
void build( ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build( v * 2, tl, tm);
        build( v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] * t[v * 2 + 1];
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) * sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] * t[v * 2 + 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            a[i] = 1;
        else if (a[i] < 0)
            a[i] = -1;
        else
            a[i] = 0;
    }
    build(1,1,n);
    ll q;
    cin >> q;
    while (q--)
    {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            if (b > 0)
            b = 1;
        else if (b < 0)
            b = -1;
        else
            b = 0;
            update(1, 1, n , a, b);
        }
        else
        {
            ll ans = sum(1, 1, n, a, b);
            if (ans < 0)
                cout << "NEGATIVE\n";
            else if (ans > 0)
                cout << "POSITIVE\n";
            else
                cout << "ZERO\n";
        }
    }
}