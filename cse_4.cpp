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
    string s;
    cin >> s;

    for (ll i = 0; i < s.length(); i++)
    {
        if (((s[i] - 48) == 8)||(s[i] - 48)==0)
        {
            cout << "YES\n"<<s[i];
            
            return 0;
        }
        for (ll j = i + 1; j < s.length(); j++)
        {
            if (((s[i] - 48) * 10 + s[j] - 48) % 8 == 0)
            {
                cout << "YES\n"
                     << ((s[i] - 48) * 10 + s[j] - 48);
                return 0;
            }
            for (ll k = j + 1; k < s.length(); k++)
            {
                if (((s[i] - 48) * 100 + (s[j] - 48) * 10 + s[k] - 48) % 8 == 0)
                {
                    cout << "YES\n"
                         << ((s[i] - 48) * 100 + (s[j] - 48) * 10 + s[k] - 48);
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
}