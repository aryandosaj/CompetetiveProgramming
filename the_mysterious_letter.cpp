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
    ll total = 13 * 27;
    ll pre[27];
    pre[0] = 0;
    for (ll i = 1; i < 27; i++)
        pre[i] = pre[i - 1] + i;
    ll n, s, q;
    cin >> n >> s >> q;
    while (q--)
    {
        ll i, j;
        cin >> i >> j;
        i--;
        ll num = i * s + j;
        num = num % total;
        auto p = upper_bound(pre, pre + 27, num);
        p--;
        //    cout<<*p<<" ";
        if (num == *p)
            num = p - pre;
        else
            num -= *p;
        if (num == 0)
            cout << "z\n";
        else
            cout  << (char)('a' - 1 + num) << "\n";
    }
}