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
ll dp[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll last = 0, t = 0, l = 0;
    ll ans = 0;
    ll flag = 0;
    for (ll i = 0; i < s.length(); i++)
    {

        if (s[i] == 'M')
            t++;
        else if(t)
        {
            ans = max(ans+1,t);
        }
    }

    cout << ans;
}