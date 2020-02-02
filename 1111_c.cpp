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
vll v;
ll n, k, a, b;
ll fun(ll low, ll high)
{
    ll na = upper_bound(v.begin(), v.end(), high) - lower_bound(v.begin(), v.end(), low);

    // cout<<low<<" "<<high<<" "<<na<<"\n";
    if (low == high)
    {
        if (na > 0)
            return b * na;
        else
            return a;
    }
    ll mid = (low + high) / 2;
    if (na > 0)
        return min(na * b * (high - low + 1), fun(low, mid) + fun(mid + 1, high));
    else
        return (a);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b;
    for (ll i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout<<fun(1,pow(2,n));
}