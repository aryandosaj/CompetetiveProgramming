#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
vector <ll> tree[100001];
ll visit[100001];
double dfs(ll u)
{
    double children=tree[u].size();
    if(u!=1)
    children--;
    if(children==0)
    return 1;
    double p = 1.0/children;
    double exp_length=0;
    visit[u]=1;
    for(int i = 0; i < tree[u].size(); i++)
    {
        ll v=tree[u][i];
        if(visit[v]==1)
        continue;
        exp_length+=(p*dfs(v));
    }
    if(u!=1)
    exp_length++;
    return exp_length;
    
}
int main()
{
    
    //code start here
    ll n;
    cin>>n;
    if(n==1)
    {cout<<"0";return 0;}
    for(int i = 0; i < n-1; i++)
    {
        ll u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    printf("%0.7lf",dfs(1));
    
}