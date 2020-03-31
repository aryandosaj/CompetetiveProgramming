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

pair<ll, vll> arr[100005];
ll dp[100005][128];
ll n, p, k;
bool comp(pair<ll, vll> a, pair<ll, vll> b)
{
    return a.first > b.first;
}
ll rec(ll ind, ll mask)
{
    // cout << ind << " " << mask << " "  << "\n";

    if (dp[ind][mask] != -1)
        return dp[ind][mask];

    ll c = 0;
    ll temp = mask;
    while (temp > 0)
        c += temp & 1, temp /= 2;
    if (ind == n)
    {
        if (c == p)
            return 0;
        return -MOD;
    }
    ll  ans = rec(ind + 1, mask);
    if (ind - c < k)
        ans += arr[ind].first;
    

    f(0, p)
    {
        ll temp = 0;
        if ((mask & (1 << i)) == 0)
            ans = max(ans, rec(ind + 1, mask | (1 << i)) + arr[ind].second[i]);
    }
    return dp[ind][mask] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n >> p >> k;
    f(0, n) cin >> arr[i].first;
    ll sum = 0;
    f(0, n)
        fi(0, p)
    {
        ll x;
        cin >> x;
        arr[i].second.pb(x);
    }
    sort(arr, arr + n, comp);
    cout << rec(0, 0);
}