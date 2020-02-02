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
    string s;
    cin >> s;
    ll arr[n + 1];
    arr[0] = s[0] == 'S' ? 1 : 0;

    ll g = 0, k = 0, c = 0;
    map<ll, ll> mp;
    if(s[0]=='G') k++,g++,c++,mp[0]++; else mp[1]++;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == 'S')
            arr[i] = arr[i - 1] + 1, g = 0,mp[arr[i]]++;
        else
        {
            arr[i] = arr[i - 1], g++, c++;
            k = max(g, k);
            mp[arr[i]]++;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if ((i == 0) && (c > (mp[0] + mp[1] - 1)))
        {
            ans = max(ans, mp[0] + mp[1]);
        }
        else if (c > (mp[i] + mp[i + 1] - 2))
            ans = max(ans, mp[i] + mp[i + 1] - 1);
    }
    ans = max(ans, k);
    cout << ans << "\n"
         ;
}