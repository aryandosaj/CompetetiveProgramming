#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
vector <pair<ll,ll> > store[100001];
ll visit[100010];
ll w_from_root[100010];
ll arr[100010];
ll child[100010];

void dfs(ll u,ll sum)
{
    if(sum<0)
    {w_from_root[u]=0;sum=0;}
    visit[u]=1;
    for(int i = 0; i < store[u].size(); i++)
    {
        ll v=store[u][i].first;
        ll w=store[u][i].second;
        if(visit[v]==1) 
        continue;
        w_from_root[v]=w_from_root[u]+w;
        
        dfs(v,sum+w);
        child[u]+=child[v]+1;

    }
    
}
ll c=0;
void count(ll u)
{
    visit[u]=1;
    for(int i = 0; i < store[u].size(); i++)
    {
        ll v=store[u][i].first;
        ll w=store[u][i].second;
        if(visit[v]==1)
        continue;
        if(w_from_root[v]>arr[v])
        {
            // cout<<"heer"<<v;
            c+=(child[v]+1);
            visit[v]=1;
            continue;
        }
        count(v);
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    
    for(ll i = 0; i < 100010; i++)
    {
        visit[i]=0;
        w_from_root[i]=0;
        child[i]=0;
    }
    
    ll n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    for(int i = 1; i <= n-1; i++)
    {
        ll w,v;
        cin>>v>>w;
        store[i+1].push_back(make_pair(v,w));
        store[v].push_back(make_pair(i+1,w));
    }
    // ll c=0;
    dfs(1,0);
    for(ll i = 0; i < 100010; i++)
    visit[i]=0;    
    count(1);

    // for(int i = 1; i <= n; i++)
    // {
    //     cout<<child[i]<<" ";
    // }
    cout<<c;
    
    
    
}
