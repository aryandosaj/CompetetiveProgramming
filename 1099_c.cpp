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
    ll k;
    cin >> k;
    ll c = 0, sn = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
            c++;
        if (s[i] == '*')
            sn++;
    }
    if ((k > (s.length() - c)) && (sn == 0))
    {
        cout << "Impossible";
        return 0;
    }
    string ans = "";
    if (k < (s.length() - sn - c))
    {
        ll x = s.length() - sn - c - k;
        for (ll i = 0; i < s.length(); i++)
        {
            if ((x != 0) && (i != (s.length() - 1)))
                if (((s[i + 1] == '?') || (s[i + 1] == '*')))
                {
                    x--;
                    continue;
                }
            if (!((s[i] == '?') || (s[i] == '*')))
                ans += s[i];
        }
        if (x == 0)
            cout << ans;
        else
            cout << "Impossible";
        return 0;
    }
    else if (k >= (s.length() - sn - c))
    {
        ll x = k - s.length() + sn + c;
        ll flag = 0;
        for (ll i = 0; i < s.length(); i++)
        {
            if (i != (s.length() - 1))
                if ((s[i + 1] == '*') && (flag == 0))
                    {
                        while (x > 0)
                        {
                            ans += s[i];
                            x--;
                        }
                        flag = 1;
                    }
            if (!((s[i] == '?') || (s[i] == '*')))
                ans += s[i];
        }
        cout << ans;
    }
}