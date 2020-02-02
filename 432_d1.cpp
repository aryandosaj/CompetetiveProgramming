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
    string s;
    cin >> s;
    ll n = s.length();
    ll lps[n + 1];
    map<ll, ll> mp;
    map<ll, ll> ans;
    lps[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        ll j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    ll temp = n - 1;
    vll v;
    for (ll i = 0; i < n; i++)
        ans[lps[i]]++;
    for (ll i = n - 1; i > 0; i--)
        ans[lps[i - 1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;
    v.push_back(n);
    while (lps[temp] != 0)
    {
        v.push_back(lps[temp]);
        temp = lps[temp] - 1;
    }
    reverse(v.begin(), v.end());
   
    cout << v.size() << "\n";

    for (auto i : v)
        cout << i << " " << ans[i] << "\n";
}