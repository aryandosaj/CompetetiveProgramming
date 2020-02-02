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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, b;
        cin >> n >> b;
        ll num = n;
        ll b_kebbad = 0;
        ll b_k=0;
        ll b_kepahele = (1ll << (b));
        if (b > 63)
        {
            cout << "0\n";
            continue;
        }
        if ((1ll << b) > n)
        {
            cout << "0\n";
            continue;
        }
        for (ll i = 0; i <= b; i++)
        {
            if(i!=b)
            b_k = b_k|((1ll<<i)&num);
            n = n >> 1;

        }
        if (n == 0)
        {
            ll ans = num - (1ll << b)+1;
            cout << ans << "\n";
            continue;
        }
        b_kebbad = n - 1;
        ll ans = b_kepahele;
        ans += b_kepahele * b_kebbad;
        if (num & (1ll << b))
            ans += b_k+1;
        cout  << ans << "\n";
    }
}