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
ll n, m;
ll arr[501][501];
ll vis[501][501];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll a, b;
    cin >> a >> b;
    priority_queue<pair<ll, pair<ll, pair<ll, ll>>>> q;
    priority_queue<pair<ll, pair<ll, pair<ll, ll>>>> temp;
    priority_queue<pair<ll, pair<ll, pair<ll, ll>>>> tem;
    q.push({-arr[a][b], {-MAX, {a, b}}});
    ll ans = 0;
    vis[a][b] = 1;
    while (!q.empty())
    {
        // if(q.empty())
        // {
        //     if(temp.empty())break;
        //     q = temp;
        //     temp=tem;
        // }
        ll c = q.top().second.first;
        ll ii = q.top().second.second.first;
        ll jj = q.top().second.second.second;
        ll l = max(arr[ii][jj], c);

        // cout<<ii<<" "<<jj<<" "<<c<<" "<<l<<" "<<abs(l)<<"\n";
        q.pop();
        ans += abs(l);
        for (ll i = -1; i <= 1; i++)
        {
            for (ll j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                ll x = ii + i;
                ll y = jj + j;
                if (x < 1 || x > n || y < 1 || y > m)
                    continue;
                if (vis[x][y] == 1)
                    continue;
                if (arr[x][y] < 0)
                    q.push({-arr[x][y], {l, {x, y}}}), vis[x][y] = 1;
            }
        }
    }
    cout << ans << "\n";
}