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
#define MAX2 1000000007
ll pp[100005];
ll pre[100005];
ll p = 53;
ll MAX = pow(2, 63) - 25;
vll arr;
ll dp[100005];
ll pre_dp[100005];
ll pre_dp1[100005];
unordered_map<ll, ll> special;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    pp[0] = 1;
    for (ll i = 1; i < 100005; i++)
        pp[i] = (pp[i - 1] * p) % MAX;
    ll t_h = 0;
    for (ll i = 0; i < t.length(); i++)
    {
        t_h += t[i] * pp[i];
        t_h = t_h % MAX;
    }
    pre[0] = 0;
    for (ll i = 1; i <= s.length(); i++)
    {
        pre[i] = (pre[i - 1] + s[i - 1] * pp[i - 1]) % MAX;
    }
    vll ind;
    for (ll i = 0; i + t.length() - 1 < s.length(); i++)
    {
        ll ch;
        ch = pre[i + t.length()] - pre[i];
        if (ch == (t_h * pp[i]) % MAX)
            ind.push_back(i + t.length() - 1), special[i + t.length() - 1] = 1;
    }
    // for (ll i = 0; i < ind.size() - 1; i++)
    // {
    //     arr.push_back(ind[i + 1] - (ind[i] + t.length()));
    // }
    // for(auto i:arr)cout<<i<<" ";
    ll ans = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (special[i])
        {
            // cout<<i<<" ";
            dp[i] = (i - t.length() + 2 + pre_dp1[i - t.length()]) % MAX2;
        }
        else
        {
            if (i != 0)
                dp[i] = dp[i - 1];
        }
        if (i != 0)
        {
            pre_dp[i] = (pre_dp[i - 1] + dp[i]) % MAX2;
            pre_dp1[i] = (pre_dp1[i - 1] + pre_dp[i]) % MAX2;
        }
        else
        {
            pre_dp[i] = dp[i];
            pre_dp1[i] = pre_dp[i];
        }
        ans += dp[i];
        ans = ans % MAX2;
        // cout<<dp[i]<<" ";
    }
    cout << ans;
}