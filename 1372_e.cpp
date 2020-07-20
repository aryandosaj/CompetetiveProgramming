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
pl arr[101][101];
ll dp[101][101];
ll n, m;

ll rec(ll l, ll r)
{
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    ll ans = 0;

    f(l, r + 1)
    {
        ll a = 0;
        fi(0, n) if (arr[j][i].first >= l && arr[j][i].second <= r) a++;
        ans = max(ans, rec(l, i - 1) + rec(i + 1, r) + a * a);
    }
    return dp[l][r] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    f(0, 101) fi(0, 101) dp[i][j] = -1;
    f(0, n)
    {
        ll l;
        cin >> l;
        fi(0, l)
        {
            ll x, y;
            cin >> x >> y;
            fii(x, y + 1)
                arr[i][k] = {x, y};
        }
    }
    
    cout<<rec(0,m-1);
}