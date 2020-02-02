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
ll BIT[1000005];
ll N = 1000005;
map<ll, ll> mp;

void update(ll i)
{
    for (; i < N; i += (i & (-i)))
        BIT[i] += 1;
}
ll query(ll i)
{
    ll ans = 0;
    for (; i > 0; i -= (i & (-i)))
        ans += BIT[i];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    ll arr[n + 1];
    ll t[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] = a[i];
    }
    t[0] = 0;
    arr[0] = 0;
    a[0] = 0;
    sort(t, t + n + 1);
    ll it = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (t[i] > t[i - 1])
        {
            it++;
            mp[t[i]] = it;
        }
    }
    for (ll i = 1; i <= n; i++)
        arr[i] = mp[a[i]];
    ll r[n + 1];
    ll aa = 0;
    r[0] = 0;
    

    for (ll i = n; i > 0; i--)
    {
        aa = (n - i) - query(arr[i]);
        r[i] = aa;
        update(arr[i]);
    }
    sort(r, r + n + 1);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (r[i] >= k)
        {
            ans += n - i;
            continue;
        }
        ll pos = lower_bound(r, r + n + 1, k - r[i]) - r;
        if (pos <= i)
        {
            ans += n - i;
            continue;
        }
        ans += n - pos + 1;
    }
    cout << ans;
}