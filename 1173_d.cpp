#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll fact[200005];
#define MAX 998244353
vll graph[200004];
ll dfs(ll u, ll p, ll f)
{

    ll ans = 1;
    ll c=0;
    for(auto i:graph[u])
    {
        if(i!=p)
        {
            c++;
            ans=(ans*dfs(i,u,1))%MAX;
        }
    }
    if(f==0)
        ans=(ans*fact[c])%MAX;
    else 
        ans=(ans*fact[(c+1)])%MAX;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    for(ll i=1;i<200005;i++)
    fact[i] = (fact[i-1]*i)%MAX;
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll ans=0;
    ans=(dfs(1,0,0)*n)%MAX;
    cout<<ans;
}