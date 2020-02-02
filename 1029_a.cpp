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
    ll n, kk;
    cin >> n >> kk;
    string s;
    cin >> s;
    string t = s;
    if(kk==1)
    {cout<<s;return 0;}
    ll a = 1;
    for (ll i = 1; i <= s.length(); i++)
    {
            ll j = 0, flag = 0;
        
            ll g = i, k = 0;
            while ( k < t.length())
            {
                if (g >= s.length())
                    break;
                if (s[g++] != t[k++])
                {
                    flag = 1;
                    break;
                }
                if (g >= s.length())
                    break;
            }
            // if((flag==1)&&(i==s.length()-1))
            // flag=0,k--;
            if (flag == 0)
            {
                
                while (k < t.length())
                {
                    s += t[k++];
                }
                a++;
                // cout<<s<<i<<"\n";
                if(a==kk)
                {cout<<s;return 0;}
            }
        
    }
}