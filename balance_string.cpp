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
        string s;
        cin >> s;
        vll v;
        ll n = s.length();
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < s.length(); i++)
            mp[s[i]]++;
        for (auto i : mp)
            v.push_back(i.second);
        sort(v.begin(), v.end(), greater<int>());
        // for (auto i : v)
        //     cout << i << " ";
        ll unq = v.size();
        ll ans = MAX;
        for (ll i = 1; i <= n; i++)
        {
            ll temp = 0;
            if (n % i == 0)
            {
                // cout << i << "\n";

                if (v.size() >= (n / i))
                {
                    ll j;
                    for (j = 0; j < (n / i); j++)
                    {
                        temp += (abs(v[j] - i));
                    }
                    for (j; j < v.size(); j++)
                        temp += v[j];
                }
                else if ((n / i) <= 26)
                {
                    for (ll j = 0; j < (n / i); j++)
                    {
                        if (j < unq)
                            temp += (abs(v[j] - i));
                        else
                            temp += (i);
                    }
                }
                else temp = 2*MAX;
                // if(temp>0)
                ans = min(ans, temp / 2);
            }
        }
        cout << ans << "\n";
    }
}