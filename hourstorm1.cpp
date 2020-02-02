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
    string s;
    cin >> s;
    ll x;
    cin>>x;
    ll hr = (s[0] - '0') * 10 + s[1] - '0';
    ll min = (s[3] - '0') * 10 + s[4] - '0';
    ll wait = 0;
    for (ll i = 1; i <= 24; i++)
    {
        for (ll j = 1; j <= 60; j++)
        {
            ll sum = hr%10+(hr/10)%10+min%10+(min/10)%10;
            if(sum%x==0)
            {
                cout<<wait<<"\n";return 0;
            }
            wait++;
            min += i;
            hr += (min / 60);
            min %= 60;
            hr %= 24;
        }
    }
    cout<<"-1";
}