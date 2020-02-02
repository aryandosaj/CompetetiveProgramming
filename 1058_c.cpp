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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += s[i] - 48;
    }
    if(sum==0)
    {cout<<"YES";return 0;}
    // cout<<sum;
    for (ll i = 2; i <= sum; i++)
    {
        if (sum % i == 0)
        {
            ll ss = 0;
            ll k = i;
            ll c=sum/i;
            while (k > 1)
            {
                for (ll j = 0; j < n; j++)
                {
                    ss += s[j] - 48;
                    if(ss==c)
                    {k--;ss=0;}
                    else if(ss>c)
                    {break;}
                }
                if(ss>c)
                break;
                
            }
            if(k==0)
            {cout<<"YES";return 0;}
        }
    }
    cout<<"NO";
}