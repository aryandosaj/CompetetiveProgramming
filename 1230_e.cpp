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
ll a[100005];
vll graph[100005];
ll ans=0;
void dfs(ll u, ll p,map<ll,ll>t)
{
    map<ll,ll>temp;
    t[0]++;
    // cout<<u<<"\n";
    for(auto i:t)
    {
        
        ll g = __gcd(i.first,a[u]);
        temp[g]+=i.second;
        ans=(ans+g*i.second)%MAX;
        // cout<<i.first<<" "<<g<<"\n";
    }
    // cout<<"\n";
    
    for (auto i : graph[u])
    {
        if (i != p)
        {
            dfs(i, u,temp);
        }
    }
    
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    map<ll,ll>s;
    dfs(1,0,s);
    cout<<ans;
}