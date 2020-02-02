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
    ll n;
    cin >> n;
    ll arr[n + 1];
    ll pre[n + 1];
    pre[0] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    ll m_val, m_ind_s, m_ind_e;
    m_val = 0, m_ind_s = 0, m_ind_e = 0;
    ll cur_sum = 0;
    ll start = 1, end = 1;
    while (end <= n)
    {
        cur_sum += arr[end++];
        if (cur_sum <= 0)
        {
            start = end;
            cur_sum = 0;
        }

        if (m_val < cur_sum)
        {
            m_ind_s = start;
            m_ind_e = end - 1;
            m_val = cur_sum;
        }

        // cout << cur_sum << " ";
    }
    // cout << m_ind_s << " " << m_ind_e;
    ll ans = 0;
    if (m_ind_s > 0)
        ans = pre[m_ind_s - 1] * (-1) + m_val;

    for (ll i = m_ind_e + 1; i <= n; i++)
    {
        ans += (-1) * arr[i];
    }
    cout << ans;
}