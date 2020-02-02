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
vector<pair<ll, ll>> graph[100];
ll den[100];
ll vis[100];
ll vis1[100];
ll vis2[100];
ll viscyc[100];
ll val_n[100];
ll val_d[100];
ll ans_n[100];
ll ans_d[100];
stack<ll> st;
ll arr[100][100];
ll cycle[100];
ll c;
void dfs(ll u)
{
    // cout<<u<<"\n";
    vis1[u] = 1;
    vis[u] = 1;
    st.push(u);
    for (auto i : graph[u])
    {
        if (vis[i.first])
        {
            cycle[i.first] = c;
            ll n = 1, d = 1;
            stack<ll> temp;
            ll last = i.first;

            while (st.top() != i.first)
            {
                n *= arr[st.top()][last];
                d *= den[st.top()];
                temp.push(st.top());
                last = st.top();
                cycle[last] = c;
                st.pop();
            }
            n *= arr[st.top()][last];
            d *= den[st.top()];
            val_n[i.first] *= n;
            val_d[i.first] *= d;
            c++;
            while (!temp.empty())
            {

                val_n[temp.top()] *= n;
                val_d[temp.top()] *= d;
                st.push(temp.top());
                temp.pop();
            }
        }
        else
        {
            dfs(i.first);
        }
    }
    st.pop();
    vis[u] = 0;
}
pair<ll, ll> fun(ll n, ll d)
{
    if (n == d)
        return {1, 1};
    return {d, d - n};
}
void dfs1(ll u, ll n, ll d, ll w, ll dd, set<ll> s)
{
    vis2[u] = 1;
    pair<ll, ll> temp;
    temp = fun(val_n[u], val_d[u]);
    if (cycle[u] && (s.find(cycle[u]) == s.end()))
        n *= temp.first,
            d *= temp.second, s.insert(cycle[u]);
    else
    {

        n *= w;
        d *= dd;
    }

    for (auto i : graph[u])
    {
        if (!vis2[i.first])
        {
            // cout<<den[u]<<"\n";
            dfs1(i.first, n, d, i.second, den[u], s);
        }
    }
    if (den[u] == 0)
    {
        ans_n[u] += n;
        ans_d[u] += d;
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
    int n;
    cin >> n;
    c = 1;
    for (int i = 0; i < n; i++)
    {
        ll p = 0;
        for (int j = 0; j < n; j++)
        {
            val_n[i] = 1;
            val_d[i] = 1;
            cin >> arr[i][j];
            p += arr[i][j];
        }
        den[i] = p;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j])
            {
                graph[i].push_back({j, arr[i][j]});
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        if (den[i] && (vis1[i] == 0))
        {
            dfs(i);
        }
    }
    set<ll>temp;
    dfs1(0, 1, 1, 1, 1,temp);

    for (ll i = 0; i < n; i++)
    {
        ll g = (__gcd(ans_d[i], ans_n[i]));
        if (g)
            cout << ans_n[i] / g << " " << ans_d[i] / g << "\n";
        else
            cout << ans_n[i] << " " << ans_d[i] << "\n";
    }
    // for(ll i=0;i<n;i++)
    // {
    //     cout<<val_n[i]<<" "<<val_d[i]<<"\n";
    // }
}