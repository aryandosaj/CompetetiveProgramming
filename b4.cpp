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
ll prod(string n)
{
    ll ans = 1;
    for (ll i = n.length()-1; i >=0; i--)
    {
        if (i == 0 && n[i] == '0')
            return ans;
        ans *= n[i] - '0';
    }
    return ans;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    string s;
    ll n;
    cin >> s;
    n = s.length();
    ll ans = prod(s);
    for (ll i = n - 1; i > 0; i--)
    {
        // cout << i << " ";
        if ((s[i] != '9'))
        {
            s[i] = '9';
            i--;
            while ((i >= 0) && (s[i] == '0'))
            {
                s[i] = '9';
                i--;
            }
            s[i]--;
            i++;
        }
        ans = max(ans, prod(s));
    }
    cout << ans;
}