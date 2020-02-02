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
    vll att, def;
    ll mi = MAX;
    for (ll i = 0; i < n; i++)
    {
        string s;
        ll num;
        cin >> s >> num;
        if (s[0] == 'A')
            att.push_back(num);
        else
            def.push_back(num);
    }
    vll a;
    for (ll i = 0; i < m; i++)
    {
        ll num;
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(def.begin(), def.end());
    sort(att.begin(), att.end());
    ll ii = 0;
    unordered_map<ll, ll> mp;
    ll c = 0;
    for (ll i = 0; i < def.size(); i++)
    {
        while (ii < m && a[ii] <= def[i])
            ii++;
        if (ii == m)
            break;
        mp[ii] = 1;
        c++;
        ii++;
    }
    ii = 0;
    ll ans = 0;
    for (ll i = 0; i < att.size(); i++)
    {
        while (ii < m && a[ii] < att[i])
        {
            ii++;
        }
        while (ii < m && mp[ii] == 1)
            ii++;
        if (ii == m)
            break;
        mp[ii] = 1;
        ans += a[ii] - att[i];
        ii++;
        c++;
    }
    if (c == n)
    {
        for (ll i = 0; i < a.size(); i++)
        {
            if (mp[i] == 0)
                ans += a[i];
        }
    }
    ll ans2 = 0;
    for (ll i = m - 1, j = 0; i >= 0; i--, j++)
    {
        if (j >= att.size())
            break;
        if (a[i] >= att[j])
            ans2 += a[i] - att[j];
        else
            break;
    }
    cout << max(ans,ans2);
}
