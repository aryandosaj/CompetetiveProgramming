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
ll fact[100001];
ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}
bool comp(ll a, ll b)
{
    return a > b;
}
ll fun(ll n)
{
    ll ret = (fact[n] * modInverse((power(2, n / 2, MAX) * fact[n / 2]) % MAX, MAX)) % MAX;
    return ret;
}
int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < 100001; i++)
    {
        fact[i] = (i * fact[i - 1]) % MAX;
    }
    // cout<<fun(2);
    ll t;
    cin >> t;

    while (t--)
    {

        ll n;
        cin >> n;
        ll arr[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n, comp);
        map<ll, ll> mp;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            if (mp[arr[i]] == 0)
                v.push_back(arr[i]);
            mp[arr[i]]++;
        }
        ll ans = 1;
        for (ll i = 0; i < v.size(); i++)
        {
            if (mp[v[i]] == 0)
                continue;
            if ((mp[v[i]] & 1) == 0)
            {
                ans = (ans * fun(mp[v[i]])) % MAX;
            }
            else
            {
                ans = (ans * ((mp[v[i + 1]] * fun(mp[v[i]] + 1)) % MAX)) % MAX;
                mp[v[i + 1]]--;
            }
            // cout << ans << " ";
        }
        cout << ans << "\n";
    }
}