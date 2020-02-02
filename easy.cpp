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
    cin>>t;
    while (t--)
    {
        ll x1, y1, x2, y2, a, b,ans1,ans2;
        cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
        // if (b >= 2 * a)
        {
            ans1 = (abs(x2 - x1) + abs(y2 - y1)) * a;
            // cout << ans << "\n";
        }
        
        {
            // ll ans;
            if (abs(x2 - x1) > abs(y2 - y1))
            {
                ans2 = (abs(y2 - y1)) * b;
                ans2 += (abs(x2 - x1) - abs(y2 - y1)) * a;
            }
            else
            {
                ans2 = (abs(x2 - x1)) * b;
                ans2 += (abs(y2 - y1) - abs(x2 - x1)) * a;
            }
        }
        ll ans3=0;
        if (abs(x2 - x1) > abs(y2 - y1))
            {
                ans3 = (abs(y2 - y1)) * b;
                ll c = (abs(x2 - x1) - abs(y2 - y1));
                if(c%2==0)
                ans3 += (abs(x2 - x1) - abs(y2 - y1)) * b;
                else if(c>0)
                ans3 += (abs(x2 - x1) - abs(y2 - y1)-1) * b+a;
            }
            else
            {
                 ans3 = (abs(x2 - x1)) * b;
                ll c = (abs(y2 - y1) - abs(x2 - x1));
                if(c%2==0)
                ans3 += (abs(y2 - y1) - abs(x2 - x1)) * b;
                else if(c>0)
                ans3 += (abs(y2 - y1) - abs(x2 - x1)-1) * b+a;
            }
            cout <<min(ans3, min(ans1,ans2)) << "\n";

    }
}