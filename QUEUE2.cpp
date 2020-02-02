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
#define MAX 1e18
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k, l;
        cin >> n >> m >> k >> l;
        ll cur_tim = m * l;
        ll arr[n + 1];
        arr[n] = MAX;

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        ll brr[n + 1];
        brr[n] = MAX;
        brr[0] = arr[0];

        for (ll i = 1; i < n; i++)
        {
            brr[i] = arr[i] - arr[i - 1];
        }

        ll dp[n + 1];
        dp[0] = l * m;
        ll mmm = MAX;
        ll temp = 0;
        for (ll i = 1; i <= n; i++)
        {

            dp[i] = dp[i - 1] - brr[i - 1] + l;

            if (mmm > dp[i])
            {

                mmm = dp[i];
                temp = arr[i - 1];
                //    cout<<temp<<"kkkk";
            }
        }
        ll x = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] < k)
                x++;
        }
        ll ans = mmm;
        ll ans2 = MAX;
        // cout << temp << "---";
        //    if(temp>k)

        ans2 = dp[0] - k + l * x + l;
        ans = min(ans, ans2);

        ll max_tim = dp[n] + arr[n - 1] + l;
        if (k > max_tim)
        {
            ans = 0;
        }
        cout << ans << "\n";
    }
}