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
    string s1, s2, s;
    cin >> s1 >> s2;
    s = s1;
    ll n = min(s1.length(), s2.length());
    if (s1.length() > s2.length())
        s = s2;
    vll factor;
    ll d1=s1.length();
    ll d2=s2.length();
    for (ll i = 1; i <= n; i++)
    {
        if ((d1% i == 0)&&(d2%i==0))
            factor.push_back(i);
    }
    ll c = 0;

    for (auto i : factor)
    {
        // cout<<i<<" ";
        string t = "";
        for (ll j = 0; j < i; j++)
            t += s[j];
        ll flag = 0;
        for (ll j = 0; j < s1.length(); j++)
        {
            if (s1[j] != t[j % i])
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        for (ll j = 0; j < s2.length(); j++)
        {
            if (s2[j] != t[j % i])
            {
                flag = 1;
                break;
            }
        }
        if(!flag)c++;

    }
    cout<<c;
}