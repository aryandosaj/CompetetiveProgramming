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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll f = n / k;
        ll r = n % k;
        string s = "";
        for (ll j = 0; j < f; j++)
            for (ll i = 0; i < k; i++)
            {
                s = s + char(i + 'a');
            }
        
        for(ll i = 0; i < r; i++)
        {
            s = s+'a';
        }
        cout<<s<<"\n";
    }
}