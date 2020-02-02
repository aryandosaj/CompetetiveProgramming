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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll x, y, s;
        cin >> x >> y >> s;
        vector<ll> h, v;
        ll hc = 0, vc = 0, last = 0,ans=0;
        for (int i = 0; i < x; i++)
        {
            ll temp;
            cin >> temp;
            h.push_back(temp);
            hc += (temp - last - 1)/s;
            last=temp;
        }
        hc += (n - last)/s;
        // cout<<last<<" "<<hc<<"\n";
        last=0;
        for (int i = 0; i < y; i++)
        {
            ll temp;
            cin >> temp;
            ans+= ((temp - last - 1)/s)*hc;
            last=temp;
        }
        ans+= ((m - last)/s)*hc;
        cout<<ans<<"\n";

    }
}