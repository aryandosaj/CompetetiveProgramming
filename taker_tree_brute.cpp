#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        ll b = 0;
        ll b1=0,b2=0;
        ll num = n;
        for(ll i=0;i<=n;i++)
        {
            ll p = __builtin_popcountll(i);
            if(p>b1)
            {
                b2 = b1;b1=p;
            }
            else
            {
                b2 = max(b2,p);
            }
        }
        cout<<n<<" "<<b1+b2<<"\n";
    }
}
