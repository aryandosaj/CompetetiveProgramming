#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define deb(x) cout << #x << "  " << x << endl;

//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll dp[1003][1003];
ll M;
ll n, k;
set<ll> s;
map<ll, ll> mp;
vll v;
ll freq[1003];
ll fact[1003];
ll dp1[1003][1003];
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    a = a % M;
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
ll ncr(ll nn, ll r)
{
    if (r == 0)
        return 1;
    if (nn < r)
        return 0;
    if (nn == 0)
        return 0;
    if (r == 1)
        return nn;
    if (nn == r)
        return 1;
    if (dp1[nn][r] != -1)
        return dp1[nn][r];
    return dp1[nn][r] = (ncr(nn - 1, r - 1) + ncr(nn - 1, r)) % M;
}

ll rec(ll ind, ll p)
{
    if (p == k)
        return 1;
    if (ind >= v.size())
        return 0;
    if (p > k)
        return 0;

    if (dp[ind][p] != -1)
        return dp[ind][p];
    ll ans = rec(ind + 1, p);
    // deb(freq[v[ind]]);
    // deb(ind);

    f(1, freq[v[ind]] + 1)
    {
        // deb(ans);
        ans = (ans + ((fact[i] * ncr(freq[v[ind]], i)) % M) * rec(ind + 1, p + i)) % M;
    }
    return dp[ind][p] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    M = 1000000007;
    f(0, 1003) fi(0, 1003) dp[i][j] = -1, dp1[i][j] = -1;
    fact[0] = 1;
    f(1, 1003) fact[i] = (fact[i - 1] * i) % M;
    ncr(1000,999);
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i], s.insert(arr[i]);
    ll c = 1;
    for (auto i : s)
        mp[i] = c++, v.pb(c-1);
    for (int i = 0; i < n; i++)
        arr[i] = mp[arr[i]], freq[arr[i]]++;

    ll num = rec(0, 0);
    ll den = (ncr(n, k) * fact[k]) % M;
    ll ans = (num * power(den, M - 2, M)) % M;
    // cout<<num<<" "<<den<<"\n";
    cout << ans;
    //f(0,5){fi(0,5){cout<<dp[i][j]<<" ";}cout<<"\n";}
    return 0;
}
