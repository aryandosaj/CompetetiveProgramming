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
#define NUM 400005
vector<pair<ll, ll>> graph[NUM];
ll vis[NUM];
ll par[NUM];
ll stflag;
vll v;
stack<ll> st;
ll flag;
stack<ll> fresh;
ll n;
void init()
{
    v.clear();
    st = fresh;
    stflag = 0;
    flag = 0;
    for (int i = 0; i < NUM; i++)
    {
        graph[i].clear();
        vis[i] = 0;
        par[i] = 0;
        par[i] = 0;
    }
};
void dfs(ll u)
{
    if (flag)
        return;
    vis[u] = 1;
    for (auto i : graph[u])
    {
        if (vis[i.first] == 0)
        {
            // cout << i.first << "\n";
            st.push(i.second);
            par[i.first] = u;
            dfs(i.first);
            st.pop();
        }
        else if (i.first != par[u])
        {
            if (flag == 0)
            {
                ll c = 1;
                stack<ll> temp = st;
                ll t = u;
                v.push_back(i.second);
                while (par[t] != i.first)
                {
                    v.push_back(temp.top());
                    temp.pop();
                    t = par[t];
                    c++;
                }
                v.push_back(temp.top());
                reverse(v.begin(), v.end());
                if (i.first > n)
                {
                    v.push_back(v[0]);
                    stflag = 1;
                }
                flag = 1;
                return;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        init();
        ll m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back({v + n, i});
            graph[v + n].push_back({u, i});
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            if (flag == 0 && vis[i] == 0)
                dfs(i);
        }
        if (flag == 0)
        {
            cout << ":(\n";
        }
        else
        {
            cout << ":)\n";
            if (stflag == 1)
            {
                cout<<v.size()-1<<"\n";
                for (int i = 1; i < v.size(); i++)
                    cout << v[i] << " ";
                cout << "\n";
            }
            else
            {
                cout<<v.size()<<"\n";
                for (auto i : v)
                    cout << i << " ";
                cout << "\n";
            }
        }
    }
}