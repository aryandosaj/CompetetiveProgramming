#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
string s[2003];
ll dp[2003][2003];
ll arr[2003];
ll n;
map<ll, ll> num_dig;
vector<string> dig;
ll d[2003];
ll rec(ll ind, ll k)
{
    // cout << ind << " " << k << "\n";
    // return 0;
    if (k < 0)
        return dp[ind][k] = 0;
    if (k == 0 && ind == n)
        return dp[ind][k] = 1;
    if (ind >= n)
        return dp[ind][k] = 0;
    if (dp[ind][k] != -1)
        return dp[ind][k];
    ll ans = 0;

    for (ll i = 9; i >= 0; i--)
    {
        if ((d[i] & arr[ind]) == arr[ind])
        {
            ll num = d[i] ^ arr[ind];
            ll b = __builtin_popcount(num);
            ans = ans | rec(ind + 1, k - b);
        }
    }
    return dp[ind][k] = ans;
}
ll fun(string ss)
{
    ll x = (1 << 6);
    ll num = 0;
    fi(0, 7)
    {
        num = num + (ss[j] - '0') * x;
        x /= 2;
    }

    return num;
}
string ans;
void calc(ll ind, ll k)
{
    if (ind >= n)
        return;
    // cout << ind << " " << k << "\n";
    for (ll i = 9; i >= 0; i--)
    {
        if ((d[i] & arr[ind]) == arr[ind])
        {

            ll num = d[i] ^ arr[ind];
            ll b = __builtin_popcount(num);
            // cout << i << " " << ind << " " << b << " " << k << "\n";
            if (k >= b)
                if (dp[ind + 1][k - b] == 1)
                {

                    ans.pb('0' + i);
                    calc(ind + 1, k - b);
                    return;
                }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dig = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    f(0, 10)
    {
        d[i] = fun(dig[i]);
        num_dig[d[i]] = i;
    }
    ll k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    f(0, n)
    {
        cin >> s[i];
        arr[i] = fun(s[i]);
    }
    rec(0, k);
    if (dp[0][k] == 1)
    {
        calc(0, k);
        cout << ans;
    }
    else
        cout << "-1\n";
}