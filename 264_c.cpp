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
#define MAX 100000000007
ll v[100005];
ll c[100005];
ll dp[100005];
bool vis[100005];

set<ll> s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    for (ll i = 0; i < n; i++)
        cin >> c[i], s.insert(c[i]);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        for (ll i = 0; i < 100005; i++)
            dp[i] = -MAX;
        ll mc1 = 0, mc2 = 0;
        dp[0]=0;
        for (ll i = 0; i < n; i++)
        {
            if (c[i] != mc1)
            {
                ll temp = max((dp[mc1] + b * v[i]), (dp[c[i]] + a * v[i]));
                dp[c[i]] = (max(temp, dp[c[i]]));
                if (dp[c[i]] >= dp[mc1])
                {
                    mc2 = mc1;
                    mc1 = c[i];
                }
                else if (dp[c[i]] >= dp[mc2])
                    mc2 = c[i];
            }
            else
            {
                ll temp = max((dp[mc1] + a * v[i]),(dp[mc2] + b * v[i]));
                dp[c[i]] = max(temp, dp[c[i]]);
            }
            // cout<<dp[mc1]<<" "<<dp[mc2]<<"\n";
        }
        cout << dp[mc1] << "\n";
        
    }
}