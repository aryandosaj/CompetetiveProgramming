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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;

    for (ll i = 0; i < k; i++)
    {
        ll t1, f1, t2, f2;
        cin >> t1 >> f1 >> t2 >> f2;
        if (((a <= f1) && (f1 <= b) )|| ((a <= f2) && (f2 <= b)))
        {
            cout << (abs(t2 - t1) + abs(f2 - f1)) << "\n";
        }
        else
        {
            ll temp = 0;
            if (abs(f1 - a) < abs(f1 - b))
                temp = a;
            else
                temp = b;
            if(t1!=t2)
            cout << (abs(f1 - temp) + abs(t2 - t1) + abs(f2 - temp)) << "\n";
            else
            cout<<abs(f2-f1)<<"\n";
        }
    }
}