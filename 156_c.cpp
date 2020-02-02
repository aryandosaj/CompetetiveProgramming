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
ll dp[101][2550] = {1};
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i < 101; i++)
        for (ll j = 0; j < 2501; j++)
            for (ll k = 0; k < 26; k++)
                (dp[i][j+k] += dp[i - 1][j])%=MAX;
    ll t;
    cin >> t;
    while (t--)
    {

        cin >> s;
        ll ans ;
        ll l = s.length();
        ll c = 0;
        for(ll i=0;i<l;i++)
            c+=s[i]-'a';
        
        cout << dp[l][c]-1 << "\n";
    }
}