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
    ll t;
    cin >> t;
    while (t--)
    {
        unordered_map<char, ll> mp;
        string s;
        cin >> s;
        ll sz = 0;
        for (ll i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 0)
                sz++;
            mp[s[i]]++;
        }
        ll n = s.size();
        ll ans = MAX;
        vll v;
        for(auto i:mp)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for (ll i = 1; i * i <= n; i++)
        {
            ll x = 0;
            ll temp = 0;
            ll c = 0;
            if ((n % i) == 0)
            {
                for (auto j : v)
                {
                    c++;
                    x += j;
                    temp += abs(i - j);
                    if (c == (n / i))
                        break;
                }
                if ((n / i) > c)
                    temp += (n / i - c) * i;
                else if (sz > c)
                    temp += (n - x);
                ans = min(ans, temp / 2);
                c = 0;
                temp = 0;
                x = 0;
                for (auto j : v)
                {
                    c++;
                    x += j;
                    temp += abs((n / i) - j);
                    if (c == i)
                        break;
                }
                if (i > c)
                    temp += (i - c) * (n / i);
                else if (sz > c)
                    temp += n - x;

                ans = min(ans, temp / 2);
            }
        }
        cout << ans << "\n";
    }
}