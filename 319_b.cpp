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
    ll arr[n];
    vll a[2];
    for (ll i = 0; i < n; i++)
        cin >> arr[i], a[0].push_back(arr[i]);
    ll c = 0;
    ll flag = 0;
    ll ans = 0;
    ll p = 1;
    while (p > 0)
    {
        p=0;
        for (ll i = a[c].size() - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                a[1 - c].push_back(a[c][i]);
            }
            else if (a[c][i] >= a[c][i - 1])
                a[1 - c].push_back(a[c][i]);
            else
                p++;
        }
        a[c].clear();
        c = 1 - c;
        reverse(a[c].begin(), a[c].end());
        for(auto i:a[c])cout<<i<<" ";cout<<"\n";
        if (p > 0)
            ans++;
    }
    cout << ans;
}