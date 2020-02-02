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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll arr[n];
        ll brr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        ll c = 0;
        ll pre_sum[n];

        for (ll i = 0; i < n; i++)
        {
            if (arr[i] == brr[i])
                c++;
            pre_sum[i] = c;
        }

        for (ll i = 0; i < q; i++)
        {
            /* code */
            ll x, y, z;
            cin >> x >> y >> z;
            x = (x ^ pre_sum[n - 1]) - 1;
            y = (y ^ pre_sum[n - 1]) - 1;
            z = z ^ pre_sum[n - 1];
            ll count = 0;
            count += x >= 1 ? pre_sum[x - 1] : 0;
            count += y >= n - 1 ? 0 : pre_sum[n - 1] - pre_sum[y];

            for (ll i = x; i <= y; i++)
            {
                if (brr[i] == z)
                    count++;
                arr[i] = z;
            }
            c=0;
            for (ll i = 0; i < n; i++)
            {
                if (arr[i] == brr[i])
                    c++;
                pre_sum[i] = c;
            }
            cout<<count<<"\n";

        }
    }
}