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
ll first_dif(string a,string b)
{
    ll len=a.length();
    for(ll i = 0; i < a.length(); i++)
        {
            if(a[i]!=b[i])
            {
                len = i+1;
                break;
            }
        }
        return len;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string str[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> str[i];
        }

        string temp;
        for (int i = 0; i < 9; ++i)
            for (int j = i + 1; j < 10; ++j)
            {
                if (str[i] > str[j])
                {
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }

        ll l,r;ll ans=0;
        ll len=0;
        
        
        l=0;r=1;
        while(1)
        {


        }
    }
}