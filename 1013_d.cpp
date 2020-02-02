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
vll graph[400005];
ll visit[400005]={0};
void dfs(ll u){
    visit[u]=1;
    
    for(ll  i = 0; i < graph[u].size()  ; i++)
    {
        ll v = graph[u][i];
        if(visit[v])
        continue;
        else
        {
            dfs(v);
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll r, c;
        cin >> r >> c;
        c+=n;
        graph[r].push_back(c);
        graph[c].push_back(r);
    }
    
    

    ll ans = -1;
    for(ll i = 1; i <= n+m; i++)
    {
       if(!visit[i])
       {
           ans++;
           dfs(i);
       }
    }
        
    cout << ans;
    
    
    // cout<<r_mx;
}