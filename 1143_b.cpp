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
    string s;
    cin >> s;
    ll ans = 1;
    ll c = 0;
    for (ll i = s.length() - 1; i >= 0; i--)
    {
        if (i != 0)
        {
            if (c == 0)
            {
                if (s[i] >= '5')
                {
                    ans *= s[i]-'0';
                }
                else
                {
                    ans *= 9;
                    c = 1;
                    continue;
                }
            }
            else
            {
                if (s[i] >= '6')
                {
                    ans *= s[i]-'0'-1;c=0;
                }
                else
                {
                    ans *= 9;
                    c = 1;
                    continue;
                }
            }
        }
        else
        {
            if(c==1)
            {
                if(s[i]=='1')continue;
                else ans*=s[i]-'0'-1;
            }
            else
            {
                ans*=s[i]-'0';
            }
            
        }
    }
    cout<<ans;
}