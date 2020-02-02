#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vll graph[100005];
unordered_map<ll,ll>mp;
set<ll>s;
ll dfs(ll u,ll p)
{
    ll x=1;
    for(ll i=0;i<graph[u].size();i++)
    {
        ll v = graph[u][i];
        if(v!=p)
            x=x&dfs(v,u);
    }
    // cout<<u<<" "<<x<<" "<<mp[u]<<"\n";

    if((x)&&mp[u])
    {s.insert(u);}
    return mp[u];
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,root;
   cin>>n;
    for(ll i=1;i<=n;i++)
    {
        ll p,c;
        cin>>p>>c;
        if(p==-1){root=i;mp[i]=c;continue;}
        graph[i].push_back(p);
        graph[p].push_back(i);
        mp[i]=c;
    }
    dfs(root,-1);
    for(auto i:s)cout<<i<<" ";
    if(s.empty())cout<<"-1";
}