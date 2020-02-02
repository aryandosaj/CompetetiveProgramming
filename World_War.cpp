#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
stack<int>s;
bool vis[100005];
void dfs(int u)
{
    s.push(u);
    vis[u]=1;
    for(auto i:graph[u])
    {
        if(vis[i])
        {
            
        }
        else dfs(i);
    }
    s.pop();
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    
}