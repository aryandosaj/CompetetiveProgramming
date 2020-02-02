#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
ll n, k;
vll graph[100001];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> lev;
unordered_map<ll, ll> child;
bool rec(ll u, ll k)
{
    vis[u] = 1;

    if (k == 0)
    {
        bool ans = 1;
        for (ll i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];
            if (!vis[v])
            {
                ans = 0;
                break;
            }
        }
        return ans;
    }
    else
    {
        bool ans = 1;
        ll c = 0;
        for (ll i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];
            if (!vis[v])
                ans = ans & rec(v, k - 1), c++;
        }
        if ((graph[u].size() != 0) && (c >= 3))
            return ans;
        else
            return 0;
    }
}
ll head = -1;
ll max_child=0;
void dfs(ll u, ll d)
{
    

    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != d)
        {
            lev[v] = lev[u] + 1;
            dfs(v, u);
            child[u]+=child[v]+1;
        }

    }
    if(lev[u]==k)
    {
        if(child[u]>max_child)
        head=u,max_child=child[u];

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll root = -1;
    for (ll i = 0; i < 100001; i++)
    {
        if (graph[i].size() == 1)
           { root = i;break;}
    }

    if (root == -1)
        cout << "No";
    else
    {
        dfs(root, root);
        if (head == -1)
        {
            cout << "No";
            return 0;
        }
        root = head;
        // cout<<head;
        bool ans = rec(root, k);

        if (ans)
            cout << "Yes";
        else
            cout << "No";
    }
}