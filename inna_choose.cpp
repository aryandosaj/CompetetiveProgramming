#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
        ll c = 0;
        set<ll> v;
        for (ll i = 0; i < s.length(); i++)
        {
            if (s[i] == 'X')
            {
                v.insert(1);
                c++;
            }
        }
        if(c==12)
        v.insert(12);
        for (ll i = 0; i < 6; i++)
        {
            if ((s[i] == 'X')&&(s[i+6]=='X'))
            {
                v.insert(2);
                break;
            }
        }
        for (ll i = 0; i < 4; i++)
        {
            if ((s[i] == 'X')&&(s[i+4]=='X')&&((s[i+8]=='X')))
            {
                v.insert(3);
                break;
            }
        }
        for (ll i = 0; i < 3; i++)
        {
            if ((s[i] == 'X')&&(s[i+3]=='X')&&((s[i+6]=='X'))&&((s[i+9]=='X')))
            {
                v.insert(4);
                break;
            }
        }
        for (ll i = 0; i < 2; i++)
        {
            if ((s[i] == 'X')&&(s[i+2]=='X')&&((s[i+4]=='X'))&&((s[i+6]=='X'))&&(s[i+8]=='X')&&(s[i+10]=='X'))
            {
                v.insert(6);
                break;
            }
        }
        cout << v.size() << " ";
        for (auto i : v)
        {
            //    if((mp[i]==0)&&(mp[12/i]==0))
            cout << i << "x" << (12 / i) << " ";
            // mp[i]++;mp[12/i]++;
        }
        cout << "\n";
    }
}