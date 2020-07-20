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
ll d, m, b;
ll dp[50];
ll rec(ll ind)
{
    
    if (ind>=0&&dp[ind] != -1)
        return dp[ind];
    ll c = ind + 1;
    ll ans = 0;
    while (c < b)
    {
        ans = (ans + rec(c) * (1 << c) + (1 << c)) % m;
        c++;
    }
    ans = (ans + (d - (1 << c) + 1)) % m;
    return dp[ind] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        f(0, 50) dp[i] = -1;
        cin >> d >> m;
        for (ll i = 30; i >= 0; i--)
            if ((1 << i) & d)
            {
                b = i;
                break;
            }
        cout << rec(-1) << "\n";
    }
}