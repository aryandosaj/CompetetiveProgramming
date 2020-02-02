#include <bits/stdc++.h>
#define MAX 1000000007
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
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}
vll graph[200010];
vll u_graph[200010];
ll visit[200010];
ll u_visit[200010];
ll intime[200010];
ll ans=1;
ll c = 0, cycle = 0;
void dfs(ll u, ll t)
{
    intime[u] = t;
    visit[u] = 1;
    
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (visit[v] == 0)
        {
            dfs(v, t + 1);
        }
        else
        {
            cycle = (t - intime[v] + 1);
        }
    }
}
void u_dfs(ll u)
{
    
    u_visit[u] = 1;
    c++;
    for (ll i = 0; i < u_graph[u].size(); i++)
    {
        ll v = u_graph[u][i];
        if (u_visit[v] == 0)
        {
            u_dfs(v);
        }
        
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout<<power(2,150000,MAX);
    for (int i = 0; i < 200010; i++)
    {
        visit[i] = 0;
        u_visit[i] = 0;
    }

    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        graph[i].push_back(arr[i]);
        u_graph[i].push_back(arr[i]);
        u_graph[arr[i]].push_back(i);
    }

    for (ll i = 1; i <= n; i++)
    {
        if (u_visit[i] == 0)
        {
            dfs(i, 1);
            u_dfs(i);
            if(cycle>0)
            ans =mulmod(ans, mulmod((power(2, cycle, MAX) - 2) , power(2, c - cycle, MAX),MAX) ,MAX);
            // cout<<cycle<<" "<<c<<"\n";
            c = 0;
            cycle = 0;
        }
    }
    cout << ans;
}