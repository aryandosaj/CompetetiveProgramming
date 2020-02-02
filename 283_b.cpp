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
ll dp[200005];
ll arr[200005];
ll n, flag;
map<ll,bool>vis;
ll rec(ll x)
{
    if(x!=1){if(vis[x])return -1;}
    if(x!=1)vis[x]=1;
    ll xx = x;
    ll y = 0;
    if ((x!=1)&&(dp[x] != 0))
        return dp[x];
    else
    {
        y += arr[x];
        x += arr[x];
        if (x > n)
            return y;
        y += arr[x];
        x -= arr[x];
        if (x < 1)
            return y;
        if (x == 1)
        {
            if (xx != 1)
                dp[xx] = -1;
            return -1;
        }
    }
    // cout<<x<<" ";
    ll xxx = rec(x);
    if (xxx == -1)
    {
        if (xx != 1)
            dp[xx] = -1;
        return -1;
    }
    else
    {
        if (xx != 1)
            dp[xx] = y + xxx;
        return y + xxx;
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n;
    ll x = 1, y = 0;
    for (ll i = 2; i <= n; i++)
        cin >> arr[i];

    for (ll i = 1; i < n; i++)
    {
        arr[1] = i;
        // if (i == 1)
        // {
        //     y += arr[1];
        //     x += arr[1];
        //     if (x > n)
        //     {
        //         cout << y << "\n";
        //         continue;
        //     }
        //     y += arr[x];
        //     x -= arr[x];
        //     if (x < 1)
        //     {
        //         cout << y << "\n";
        //         continue;
        //     }
        //     ll r = rec(x);
        //     if(r==-1){cout<<"-1\n";}
        //     else{cout<<y+r<<"\n";}
        //     continue;
        // }
        cout << rec(1) << "\n";
        vis.clear();
    }
}