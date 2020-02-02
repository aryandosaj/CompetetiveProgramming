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
        ll flag = 0;
        for(int i = 0; i < s.length(); i++)
        {
            for (int j = 1; j <= 9; j++)
                {
                    
                }
        }
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '.')
            {
                int x = s[i] - 48;
                
                for (int j = 1; j <= 9; j++)
                {

                }
            }
        }
    }
}