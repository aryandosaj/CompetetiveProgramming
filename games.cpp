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
    ll n;
    cin >> n;
    vll v;
    ll a = 0;
    ll ans = 0;
    ll num = 1;
    for (ll i = 0; i < n; i++)
    {
        ll p, q;
        cin >> p >> q;
        if (q == 0)
            v.push_back(p);
        else
            ans += p,
                num += q - 1;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (ll i = 0; i < v.size(); i++)
    {
        ans += v[i];
        num--;
        if (num == 0)
            break;
    }
    cout << ans;
}