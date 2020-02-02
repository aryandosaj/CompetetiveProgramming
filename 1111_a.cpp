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
int isv(char a)
{
    if ((a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u'))
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    if(s.size() != t.size())
    {
        cout << "No";
        return 0;
    }
    for (ll i = 0; i < s.length(); i++)
    {
        if ((isv(s[i])) != (isv(t[i])))
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}