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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    ll mm = 0;

    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll ans = 0;
    mm = MAX;
    ll last=-1;
    for (ll i = 1; i < n; i++)
    {
        if(last)
        if (arr[i] < arr[i - 1])
        {
            ll step1 = m - mm;
            ll step2 = arr[i - 1] - arr[i];

            if (step2 < step1)
                 ans = max(ans, step2);
            else
                ans = max(ans, step1);
        }
        if (arr[i] != 0)
            mm = min(mm, arr[i]);
    }
    cout << ans;
}