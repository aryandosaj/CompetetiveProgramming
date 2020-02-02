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
    ll n;
    cin >> n;
    double xx[n], yy[n];
    unordered_map<double, unordered_map<double, ll>> mp;
    for (ll i = 0; i < n; i++)
        cin >> xx[i] >> yy[i];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            double m;
            double c;
            if (xx[i] != xx[j])
            {
                m = (yy[i] - yy[j]) / (xx[i] - xx[j]);
                c = yy[i] - m * xx[i];
            }
            else
            {
                m = MAX;
                c = xx[i];
            }
            mp[m][c]=1;
        }
    }
    ll c = mp.size();
    ll num=0;
    for (auto i : mp)
        num+=i.second.size();
    ll ans = (c * (c - 1)) / 2;
    ll x=0;
    for (auto i : mp)
    {
            if(i.second.size()>1)
            {
                ans += (num-i.second.size()-x)*(i.second.size()-1);
                x+=i.second.size()-1;
            }
    }
    cout<<ans;
}