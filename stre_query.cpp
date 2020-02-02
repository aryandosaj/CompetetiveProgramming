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
ll bit[27][200005];
map<char, ll> mp;
ll N = 200005;
void update(ll i, char c, ll v)
{
    for (; i < N; i += (i & (-i)))
        bit[c - 'a'][i] += v;
}
ll query(ll i, char c)
{
    ll ans = 0;
    for (; i > 0; i -= (i & (-i)))
        ans += bit[c - 'a'][i];
    return ans;
}
ll orig(ll k, char c)
{
    ll w=k;
    ll r = query(k, c);
    k += r;
    while (r!=0)
    {
        r = query(k,c)-query(w,c);
        w=k;k+=r;
    }
    return k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll c = 0; c < 27; c++)
        for (ll i = 0; i < N; i++)
            bit[c][i] = 0;
    string s;
    cin >> s;
    ll q;
    cin >> q;
    map<char, map<ll, ll>> vis;
    while (q--)
    {
        ll k;
        char c;
        cin >> k >> c;
        k = orig(k, c);
        vis[c][k] = 1;
        update(k, c, 1);

    }
    map<char, ll> f;
    string ans = "";
    for (ll i = 0; i < s.length(); i++)
    {
        f[s[i]]++;
        if (vis[s[i]][f[s[i]]] == 0)
            ans += s[i];
    }
    cout << ans;
}