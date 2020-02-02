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
ll calc(ll x)
{
    ll r = 0;
    while (x > 0)
        r += x, x /= 2;
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        priority_queue<ll> pq;
        ll n, a, b, x, y, z, sum = 0, days;
        cin >> n >> a >> b >> x >> y >> z;
        days = ceil((z - b) / (y*1.0));
        ll c[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> c[i];
            pq.push(c[i]);
            sum += calc(c[i]);
        }
        if (a + (days - 1) * x >= z)
        {
            cout << "0\n";
            continue;
        }

        if (sum + a + (days - 1) * x < z)
        {
            cout << "RIP\n";
            continue;
        }

        sum = a + (days - 1) * x;
        ll ans = 0;
        while (sum < z)
        {
            ll p = pq.top();
            pq.pop();
            sum += p;
            pq.push(p / 2);
            ans++;
        }
        cout<<ans<<"\n";
    }
}