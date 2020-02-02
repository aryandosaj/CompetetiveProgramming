#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    ll N = 3005;
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<int>> party[N], copy[N];

    for (ll i = 0; i < n; i++)
    {
        ll p, c;
        cin >> p >> c;
        party[p].push(c);
    }
    ll ans = 1e18;
    for (ll i = 0; i <= n; i++)
    {
        priority_queue<ll, vector<ll>, greater<int>> T;

        ll current_votes = party[1].size();
        ll cost = 0;
        for (ll j = 1; j < N; j++)
        {
            copy[j] = party[j];
        }

        for (ll j = 2; j < N; j++)
        {
            while (copy[j].size() > i)
            {
                current_votes++;
                cost += copy[j].top();
                copy[j].pop();
            }
            while (!copy[j].empty())
            {
                T.push(copy[j].top());
                copy[j].pop();
            }
        }
        while ((current_votes <= i) && (!T.empty()))
        {
            current_votes++;
            cost += T.top();
            T.pop();
        }
        if (current_votes > i)
            ans = min(ans, cost);
        // cout << ans << "---\n";
    }
    cout << ans;
}