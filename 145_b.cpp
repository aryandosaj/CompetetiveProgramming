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
    ll a1, a2, a3, a4;
    ll x1, x2, x3, x4;
    cin >> a1 >> a2 >> a3 >> a4;
    x1 = a1, x2 = a2, x3 = a3, x4 = a4;
    if (abs(a3 - a4) > 1)
        cout << "-1";
    else
    {
        string s = "";
        if (a3 > a4)
        {

            for (ll i = 0; i < a3; i++)
            {
                s.push_back('4');
                s.push_back('7');
            }
            a1 -= a3;
            a2 -= a3;
            if (a1 < 0)
            {
                cout << "-1";
                return 0;
            }
            else if (a2 < 0)
            {
                cout << "-1";
                return 0;
            }
            else
            {
                string t1 = "", t2 = "";
                for (ll i = 0; i < a1; i++)
                    t1.push_back('4');
                for (ll i = 0; i < a2; i++)
                    t2.push_back('7');
                for (ll i = 0; i < s.length(); i++)
                {
                    if (s[i] == '4')
                    {
                        s.replace(i, 0, t1);
                        break;
                    }
                }
                for (ll i = s.length() - 1; i >= 0; i--)
                {
                    if (s[i] == '7')
                    {
                        s.replace(i, 0, t2);
                        break;
                    }
                }
            }
        }
        else if (a4 > a3)
        {

            for (ll i = 0; i < a4; i++)
            {
                s.push_back('7');
                s.push_back('4');
            }
            a1 -= a4;
            a2 -= a4;
            if (a1 < 0)
            {
                cout << "-1";
                return 0;
            }
            else if (a2 < 0)
            {
                cout << "-1";
                return 0;
            }
            else
            {
                string t1 = "", t2 = "";
                for (ll i = 0; i < a1; i++)
                    t1.push_back('4');
                for (ll i = 0; i < a2; i++)
                    t2.push_back('7');
                for (ll i = 0; i < s.length(); i++)
                {
                    if (s[i] == '4')
                    {
                        s.replace(i, 0, t1);
                        break;
                    }
                }
                for (ll i = s.length() - 1; i >= 0; i--)
                {
                    if (s[i] == '7')
                    {
                        s.replace(i, 0, t2);
                        break;
                    }
                }
            }
        }
        else
        {
            if (a1 >= a3 + 1)
            {
                for (ll i = 0; i < a3; i++)
                {
                    s.push_back('4');
                    s.push_back('7');
                }
                s.push_back('4');
                a1 -= a3 + 1;
                a2 -= a3;
            }
            else
            {
                for (ll i = 0; i < a3; i++)
                {
                    // s += "74";
                    s.push_back('7');
                    s.push_back('4');
                }
                s.push_back('7');
                a2 -= a3 + 1;
                a1 -= a3;
            }

            if (a1 < 0)
            {
                cout << "-1";
                return 0;
            }
            else if (a2 < 0)
            {
                cout << "-1";
                return 0;
            }
            else
            {
                string t1 = "", t2 = "";
                for (ll i = 0; i < a1; i++)
                    t1.push_back('4');
                for (ll i = 0; i < a2; i++)
                    t2.push_back('7');
                for (ll i = 0; i < s.length(); i++)
                {
                    if (s[i] == '4')
                    {
                        s.replace(i, 0, t1);
                        break;
                    }
                }
                for (ll i = s.length() - 1; i >= 0; i--)
                {
                    if (s[i] == '7')
                    {
                        s.replace(i, 0, t2);
                        break;
                    }
                }
            }
        }
        unordered_map<ll, ll> mp;
        string t = "";
        for (ll i = 0; i < s.length() - 1; i++)
        {
            mp[s[i] - '0']++;
            if (s[i] == '4' && s[i + 1] == '7')
                mp[47]++;
            if (s[i] == '7' && s[i + 1] == '4')
                mp[74]++;
        }
        mp[s[s.length() - 1] - '0']++;
        if (mp[4] == x1 && mp[7] == x2 && mp[47] == x3 && mp[74] == x4)
            cout << s;
        else
            cout << "-1";
    }
}