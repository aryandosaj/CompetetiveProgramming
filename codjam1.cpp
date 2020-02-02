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
    ll t, x = 0;
    cin >> t;
    while (t--)
    {
        x++;
        string n;
        cin >> n;
        string s1 = "", s2 = "";
        for (ll i = 0; i < n.length(); i++)
        {
            if (n[i] == '4')
                s1.push_back('3'), s2.push_back('1');
            else
                s1.push_back(n[i]), s2.push_back('0');
        }
        cout << "Case #" << x << ": " << s1 << " ";
        ll flag = 0;
        for (ll i = 0; i < s2.length(); i++)
        {
            if ((flag == 0) && s2[i] == '0')
                continue;
            if (flag)
                cout << s2[i];
            else if (s2[i] != 0)
                cout << s2[i], flag = 1;
        }
        cout<<"\n";
    }
}