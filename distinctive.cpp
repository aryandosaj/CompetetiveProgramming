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
ll fun(string s)
{
    ll a = 0;
    ll m = 1;
    for (auto i : s)
    {
        a += m * (i - '0');
        m *= 2;
    }
    return a;
}
bool vis[2000005];
ll dist[2000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<string> v;
    vll arr;
    queue<pair<ll,ll>> q;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
        ll num = fun(s);
        arr.push_back(num);
        q.push({num,num});
        vis[num]=1;
    }
    ll ans=0,an=0;
    while (!q.empty())
    {
        ll u = q.front().first;
        q.pop();
        for (int i = 0; i < k; i++)
        {
            ll num;
            num = u ^ (1 << i);
            if (!vis[num])
            {
                dist[num] = dist[u]+1;
                q.push({num,q.front().second});
                vis[num] = 1;
                if(ans<dist[num])
                {
                    ans=dist[num];
                    an = num;
                }
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        if(an&(1<<i))cout<<"1";
        else cout<<"0";
    }
}