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
#define MAX 10000000007
vll graph[300005];
ll arr[300005];
ll sum = 0, k = 0;
ll c = 0;
map<ll, ll> vis;
void dfs(ll u)
{
    // cout<<arr[u]<<" ";
    vis[u] = 1;
    sum += arr[u];
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if ((!vis[v]) && (arr[v] > 0))
        {
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll mm = -MAX, vv = 0;
    map<ll, ll> mp;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        mm = max(mm, arr[i]);
    }

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vll comp;

    if (mm > 0)
    {
        map<ll,ll> gg;ll mnm=0;
        for (ll i = 1; i <= n; i++)
        {
            if ((!vis[i]) && (arr[i] > 0))
            {
                dfs(i);

                comp.push_back(sum);
                mnm = max(mnm,sum);
                // cout<<sum<<"--";
                gg[sum]++;
                c = 0;
                sum = 0;
            }
        }
        
        cout << mnm*gg[mnm] << " " << gg[mnm];
        return 0;
    }
    else
    {
        if (mm == 0)
        {

            for (ll i = 1; i <= n; i++)
            {
                if (arr[i] == 0)
                    k++;
            }
            cout << mm << " " << k;
        }
        else if (mm == -1)
        {
            for (ll i = 1; i <= n; i++)
            {
                if (arr[i] == -1)
                    k++;
            }
            cout << mm * k << " " << k;
        }
        else
        {
            cout << mm << " 1";
        }
    }
}