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
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll len;
    cin >> len;
    string s;
    cin >> s;
    ll x3, y3;
    x3 = 0, y3 = 0;
    ll h = 0, v = 0;
    ll hh[len+1], vv[len+1];
    hh[0]=0;vv[0]=0;
    for (ll i = 0; i < len; i++)
    {
        if (s[i] == 'U')
            v++;
        if (s[i] == 'D')
            v--;
        if (s[i] == 'L')
            h--;
        if (s[i] == 'R')
            h++;
        hh[i+1] = h;
        vv[i+1] = v;
    }
    ll low = 0, high = 1e15;
    ll mid = 0,ans=-1;
    while (low <= high)
    {
        // cout<<ans<<"\n";
        mid = (low + high) / 2;


        ll x = mid / len;
        ll y = mid%len;
        x3 = x1 + h * x;
        y3 = y1 + v * x;
        x3+=hh[y];
        y3+=vv[y];

        if(abs(x3-x2)+abs(y3-y2)<=mid)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        

    }
    cout<<ans;
}