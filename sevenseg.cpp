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
ll bin(string s)
{
    ll ans = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        ans += (1 << i) * (s[i] - '0');
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<ll, ll> mp;
    mp[1] = bin("0110000");
    mp[2] = bin("1101101");
    mp[3] = bin("1111001");
    mp[4] = bin("0110011");
    mp[5] = bin("1011011");
    mp[6] = bin("1011111");
    mp[7] = bin("1110000");
    mp[8] = bin("1111111");
    mp[9] = bin("1111011");
    mp[0] = bin("1111110");

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll x, y;
        for (ll i = 0; i < n; i++)
        {
            ll xx, yy;
            cin >> xx >> yy;
            x.push_back(xx);
            y.push_back(yy);
        }
        ll mi = MAX;
        ll ma = 0;
        for (ll i = 0; i < 1 << 7; i++)
        {
            ll flag = 0;
            for (ll j = 0; j < n; j++)
            {
                if (__builtin_popcount(i & mp[x[j]]) != y[j])
                {
                    flag = 1;
                    break;
                }
            }
            ll v = 7 - __builtin_popcount(i);
            if (!flag)
            {
                
                mi = min(mi, v);
                ma = max(ma, v);
            }
        }
        if (mi!=MAX)
            cout << mi << " " << ma << "\n";
        else
            cout << "invalid\n";
    }
}