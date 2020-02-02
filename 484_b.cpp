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
    ll n;
    cin >> n;
    vll arr;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (mp[x] == 0)
            arr.push_back(x), mp[x] = 1;
        ;
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for (ll i = arr.size() - 1; i >= 0; i--)
    {
        ll j = 2;
        while ((arr[i] / j) > ans)
        {
            ll ind = upper_bound(arr.begin(), arr.end(), arr[i] / j) - arr.begin();
            if (ind != arr.size())
                ans = max(ans, arr[i] % arr[ind]);
            j++;
        }
    }
    cout << ans;
}