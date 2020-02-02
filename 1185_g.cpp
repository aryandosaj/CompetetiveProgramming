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
    ll t, g;
};
ll fact[51];
ll dp[50][4][50][50][50];
ll rec(ll n, ll g, unordered_map<ll, ll> mp)
{
    if (dp[n][g][mp[1]][mp[2]][mp[2]] != -1)
        return dp[n][g][mp[1]][mp[2]][mp[2]];
    ll ans = 0;
    if (mp[1] == 0 && mp[2] == 0 && mp[3] == 0)
        return 1;
    for (ll i = 1; i <= 3; i++)
    {
        if ((i != g) && (mp[i] > 0))
        {
            mp[i]--;
            ans = (ans + rec(n - 1, i, mp)) % MAX;
            mp[i]++;
        }
    }
    return dp[n][g][mp[1]][mp[2]][mp[2]] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 0; i < 50; i++)
        for (ll j = 0; j < 4; j++)
            for (ll k = 0; k < 50; k++)
                for (ll l = 0; l < 50; l++)
                    for (ll y = 0; y < 50; y++)
                        dp[i][j][k][l][y] = -1;
    fact[0] = 1;
    for (ll i = 1; i <= 50; i++)
        fact[i] = (fact[i - 1] * i) % MAX;
    ll n, T;
    cin >> n >> T;
    dt song[n];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        cin >> song[i].t >> song[i].g;
    for (ll i = 0; i < (1 << n); i++)
    {
        ll time = 0, num = 0;
        unordered_map<ll, ll> mp;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                time += song[j].t;
                mp[song[j].g]++;
                num++;
            }
        }
        if (time == T)
            ans = (ans + (((((rec(num, 0, mp) * fact[mp[1]]) % MAX) * fact[mp[2]]) % MAX) * fact[mp[3]]) % MAX) % MAX;
    }
    cout << ans;
}
