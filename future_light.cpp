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
        ll n;
        cin >> n;
        ll arr[n + 1];
        ll t=0;
        for (ll i = 0; i < n + 1; i++)
        {
            cin >> arr[i];
            t+=arr[i];
            if(((t&1)==0)&&(i!=n))
            {
                t++;
            }
             
        }
        cout<<t<<"\n";
    }
}