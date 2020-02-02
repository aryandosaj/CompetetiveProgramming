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
unordered_map<ll, ll> row;
unordered_map<ll, ll> col;
unordered_map<ll, ll> row1;
unordered_map<ll, ll> col1;
unordered_map<ll, ll> row2;
unordered_map<ll, ll> col2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll r, c;
        cin >> r >> c;
        row[r]++;
        col[c]++;
    }
    ll ans = 0;
    for (ll i = 2; i <= n / 2; i++)
    {
        if ((row[i] == 0))
        {
            row1[i] = 1;
            ans++;
        }
    }
    for (ll i = max((n / 2)+1, (ll)2); i < n; i++)
    {
        if ((row[i] == 0))
        {
            row2[i] = 1;
            ans++;
        }
    }
    for (ll i = 2; i < n; i++)
    {
        if (col[i] == 0)
            if ((row1[i] == 0) && (row2[n - i + 1] == 0))
            {
                ans++;
                col1[i] = 1;
            }
    }
    // cout<<ans<<"\n";

    for (ll i = 2; i < n; i++)
    {
        if (col[i] == 0)
            if (col1[i] == 0)
            {
                if ((row2[i] == 0) && (row1[n - i + 1] == 0))
                {
                    ans++;
                    col2[i] = 1;
                }
            }
    }
    cout << ans;
}