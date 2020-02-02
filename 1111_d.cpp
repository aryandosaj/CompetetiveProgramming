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
ll fact[100005];
ll inv(ll t)
{
    return power(t, MAX - 2, MAX);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    unordered_map<char, ll> mp;
    fact[0] = 1;
    for (ll i = 1; i < 100005; i++)
        fact[i] = (fact[i - 1] * i) % MAX;

    for (ll i = 0; i < s.length(); i++)
        mp[s[i]]++;

    ll n = s.length();
    ll t = 1;
    for (auto i : mp)
        (t *= fact[i.second])%=MAX;
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        ll a = mp[s[x]];
        ll b = mp[s[y]];
        if (s[x] == s[y])
            b = 0;
        if (a + b > (n / 2))
        {
            cout << "0\n";
            continue;
        }
        else
        {
            // ll ans = (((fact[n / 2] * power(fact[mp[s[x]] + mp[s[y]]], MAX - 2, MAX)) % MAX) * power(fact[n / 2 - mp[s[x]] - mp[s[y]]], MAX - 2, MAX)) % MAX;
            // ans = (ans * fact[n - mp[s[x]] - mp[s[y]]]) % MAX;

            // for (auto i : mp)
            // {
            //     if ((i.first != s[x]) || (i.first != s[y]))
            //         (ans *= power(i.second, MAX - 2, MAX)) %= MAX;
            // }
            // (ans *= 2) % MAX;
            // ll a = fact[mp[s[x]] + mp[s[y]]];
            // ll b = power(fact[mp[s[x]]], MAX - 2, MAX);
            // ll c = power(fact[mp[s[y]]], MAX - 2, MAX);
            // // cout<<a<<" "<<b<<" "<<c<<" \n";
            // (ans *= (((a * b) % MAX) * c) % MAX) %= MAX;
            // cout << ans << "\n";

            ll c = fact[n / 2];
            // (c *= inv(t))%=MAX;
            ll d = fact[n - a - b];
            (c *= (d*2))%=MAX;
            d = (t*(fact[n / 2 - a - b]))%MAX;
            d = inv(d)%MAX;
            ll ans = (c * d)%MAX;
            cout << ans << "\n";
        }
    }
}
