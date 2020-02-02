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
bool dig(ll n, ll d)
{
    while (n > 0)
    {
        if ((n % 10) == d)
            return 1;
        n /= 10;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll dp[16];
    map<ll, ll> mp;
    mp[0] = 2;
    mp[1] = 3;
    mp[2] = 5;
    mp[3] = 7;
    ll ans = 0;
    ll aa=0;
    for (ll j = 1; j < 16; j++)
    {
        ll a, b, c, d, e;
        e = __popcntd(j);
        for (ll i = 0; i < n; i++)
        {
            ll flag=0;
            for (ll k = 0; k < 4; k++)
            {
                if (j & (1 << k))
                {
                    if(!dig(arr[i],mp[k]))
                    {
                        flag=1;break;
                    }
                }
            }
            if(!flag)
            ans++;
        }
        if(e%2==1)
        {
            if(ans>2)
            aa+=((ans-2)*(ans-1)*ans)/6;
        }
        else
        {
            if(ans>2)
            aa-=((ans-2)*(ans-1)*ans)/6;

        }
        ans=0;
    }
    // cout<<__popcntd(3)<<" -";
    cout<<aa;
}