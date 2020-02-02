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
#define MAX 1e18
struct node
{
    ll z, t, f;
};
ll arr[1005][1005];
node dp[1005][1005];
char p[1005][1005];
node zero(ll i)
{
    node t;
    t.z = 0;
    t.t = 0;
    t.f = 0;
    while (((i % 10) == 0) && (i > 0))
        i /= 10, t.z++;
    while (((i % 5) == 0) && (i > 0))
        i /= 5, t.f++;
    while (((i % 2) == 0) && (i > 0))
        i /= 2, t.t++;
    return t;
}
string path;

void trace(ll i, ll j)
{
    if ((i == 0) && (j == 0))
    {
        return;
    }
    char pp = p[i][j];
    if (pp == 'D')
    {
        trace(i - 1, j);
        path += 'D';
    }
    else
    {
        trace(i, j - 1);
        path += 'R';
    }
}

node rec(ll i, ll j, node x)
{
    // if (dp[i][j].z != -1)
    //     return dp[i][j];
    if ((i == 0) && (j == 0))
        return dp[i][j] = zero(arr[i][j]);
    node u, l;
    u.z = MAX;
    l.z = MAX;
    u.t = MAX;
    l.t = MAX;
    u.f = MAX;
    l.f = MAX;
    node c = zero(arr[i][j]);
    node r;
    r.z = c.z + x.z ;
    r.t = c.t + x.t;
    r.f = c.f + x.f ;
    if (i > 0)
        l = rec(i - 1, j, r);
    if (j > 0)
        u = rec(i, j - 1, r);
    node ans;
    if ((u.z + r.z + min(r.t + u.t, r.f + u.f)) < (l.z + r.z + min(r.t + l.t, r.f + l.f)))
    {
        ans.z = u.z + c.z + min(u.t + c.t, c.f + u.f);
        ans.t = u.t + c.t - min(u.t + c.t, c.f + u.f);
        ans.f = u.f + c.f - min(u.t + c.t, c.f + u.f);
        p[i][j] = 'R';
    }
    else
    {
        ans.z = l.z + c.z + min(l.t + c.t, c.f + l.f);
        ans.t = l.t + c.t - min(l.t + c.t, c.f + l.f);
        ans.f = l.f + c.f - min(l.t + c.t, c.f + l.f);
        p[i][j] = 'D';
    }
    dp[i][j] = ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    for (ll i = 0; i < 1005; i++)
    {
        for (ll j = 0; j < 1005; j++)
        {
            dp[i][j].z = -1;
            dp[i][j].t = -1;
            dp[i][j].f = -1;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    node x;
    x.z = 0;
    x.f = 0;
    x.t = 0;
    cout << rec(n - 1, n - 1, x).z << "\n";
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j].z << " ";
    //     }
    //     cout << "\n";
    // }
    trace(n - 1, n - 1);
    cout << path;
}