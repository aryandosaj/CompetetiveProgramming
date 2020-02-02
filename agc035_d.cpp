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
ll n;
ll rec(ll msk, vll v)
{
    cout<<msk<<"\n";
    for(auto i:v)cout<<i<<" ";
    cout<<"\n";
    ll ans = MAX;
    for (ll i = 1; i < n - 1; i++)
    {
        vll temp = v;
        if ((1 << i) & msk)
        {
            ll j;
            for (j = i + 1; j < n; j++)
                if ((1 << j) & msk)
                    break;
            temp[j] += temp[i];
            for (j = i - 1; j >= 0; j--)
                if ((1 << j) & msk)
                    break;
            temp[j] += temp[i];
            temp[i] = -1;
            ans = min(ans, rec((1 << i) ^ msk, temp));
        }
    }
    if (ans == MAX)
        return v[0] + v[n - 1];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vll arr;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        arr.push_back(a);
    }
    ll MSK = (1 << n) - 1;

    ll ans = rec(MSK, arr);
    cout << ans;
}