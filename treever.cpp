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
bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second * b.first < a.first * b.second;
}
vll graph[100005];

ll val[100005];
ll invcnt[100005];
ll zo[2][100005];
void dfs(ll u, ll p)
{
    vector<pair<ll, ll>> seq;
    invcnt[u] = 0;
    zo[val[u]][u] = 1;
    for (auto i : graph[u])
        if (i != p)
            dfs(i, u), invcnt[u] += invcnt[i], zo[0][u] += zo[0][i], zo[1][u] += zo[1][i], seq.push_back({zo[0][i], zo[1][i]});
    if(val[u])
        invcnt[u] += zo[0][u];        
    sort(seq.begin(),seq.end(),compare);
    ll post[seq.size()];
    post[seq.size()-1]=0;
    for(int i=seq.size()-2;i>=0;i--)
        post[i] = post[i+1]+seq[i+1].first; 
    for(int i=0;i<seq.size();i++)
        invcnt[u]+=post[i]*seq[i].second;
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
        for (int i = 0; i < 100005; i++)
        {
            zo[0][i]=0;
            zo[1][i]=0;
            graph[i].clear();
        }
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> val[i];
        for (int i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(1, 0);
        cout<<invcnt[1]<<"\n";
    }
}