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
    ll o, e;
};
dt bit[100005];
dt a[100005];
ll N = 100005;
void update(ll i, dt temp)
{
    for (; i < N; i += (i & (-i)))
        bit[i].e += temp.e, bit[i].o += temp.o;
    // cout<<i<<" ";
}
dt query(ll i)
{
    dt temp;
    temp.o = 0;
    temp.e = 0;
    for (; i > 0; i -= (i & (-i)))
        temp.o += bit[i].o, temp.e += bit[i].e;
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < N; i++)
    {
        a[i].e = 0;
        a[i].o = 0;
        bit[i].e = 0;
        bit[i].o = 0;
    }
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        dt temp;
        temp.e = 0, temp.o = 0;
        if (x & 1)
            temp.o = 1;
        else
            temp.e = 1;
        update(i, temp);
        a[i] = temp;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
        {
            dt temp;
            dt temp2;
            temp.o = 0;
            temp.e = 0;
            if (y & 1)
                temp.o = 1;
            else
                temp.e = 1;
            temp2=temp;
            temp.o -= a[x].o;
            temp.e -= a[x].e;
            a[x]=temp2;
            update(x, temp);
        }
        else if (t == 1)
        {
            ll ans = query(y).e - ((x == 1 )? 0 : query(x - 1).e);
            cout << ans << "\n";
        }
        else
        {
            ll ans = query(y).o - ((x == 1) ? 0 : query(x - 1).o);
            cout << ans << "\n";
        }
    }
}