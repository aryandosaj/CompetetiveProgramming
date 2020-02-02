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
ll dp[10][32][1000];
ll vis[10];

ll arr[10][10];
ll n;
ll ans_len;
string ans_id;
vll graph[10];
ll t[10];
ll f = 0;
void dfs(ll u, ll mask, ll tim)
{
    vis[u] = 1;

    if (u == n + 1 && tim >= 0)
    {
        ll len = 0;
        string id = "";
        for (int i = 1; i <= n; i++)
        {
            if (mask & (1 << i))
                len++, id.push_back('0' + i);
        }
        if (len > ans_len)
        {
            ans_len = len;
            ans_id = id;
        }
        else if (len == ans_len)
        {
            if (ans_id.compare(id) > 0)
            {
                ans_id = id;
            }
        }
        cout<<id<<"\n";
    }
    for (int i = 0; i < n + 2; i++)
    {
        if (u != i)
        {
            if ((!(mask & (1 << i))) && vis[i] == 0)
                dfs(i, (mask | (1 << i)), tim - arr[u][i]);
        }
    }
    vis[u] = 0;
}
void dfs1(ll u, ll tim)
{
    vis[u] = 1;
    t[u] = tim;
    for (int i = 0; i < n + 2; i++)
    {
        if (vis[i] == 0)
        {
            dfs1(i, tim - arr[u][i]);
        }
        else
        {
            if (tim - arr[u][i] > t[i])
            {
                f = 1;
                return;
            }
        }
    }
    vis[u] = 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tim;
    cin >> n >> tim;

    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < n + 2; j++)
        {
            cin >> arr[i][j];
            graph[i].push_back(j);
        }
    map<ll,ll>depth;
    dfs1(0, 0);
    if (f == 0)
        {
            stack<pair<ll,ll>>st;
            st.push({0,tim,1});
            map<pair<ll,ll>,ll>depth;
            while (!st.empty()) 
            {
                ll u = st.top().first;
                ll t = st.top().second;
                st.pop();
                for(auto i:graph[u])
                {
                    if(i!=u)
                    {
                        st.push({i,t-arr[u][i]});
                    }
                }
            }
            
            // dfs(0, 0, tim);
            
        }
    else
    {
        // cout<<"herre";
        for (int i = 1; i <= n; i++)
            cout << i;
        return 0;
    }

    cout << ans_id;
}