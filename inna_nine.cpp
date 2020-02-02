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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll l = s.length();
    ll s_ind = 0, e_ind = 0;
    ll flag = 0;
    ll c = 1;
    for (ll i = 0; i < l - 1; i++)
    {
        if (((s[i] - 48) + (s[i + 1] - 48) == 9) && (flag == 0))
        {
            flag = 1;
            s_ind = i;
        }
        else if ((flag == 1) && ((s[i] - 48) + (s[i + 1] - 48) != 9))
        {
            flag = 0;
            if ((i - s_ind + 1) % 2 == 1)
            {
                c*=(i - s_ind + 1)/2+1;
            }
        }
    }
    if (flag == 1)
    {
        if ((l - s_ind) % 2 == 1)
        {
            c*=(l - s_ind)/2+1;
        }
    }
    cout << c;
}