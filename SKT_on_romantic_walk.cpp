#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vll graph[100005];
int node,d;
void dfs(int u,int p,int l)
{
    // cout<<u<<"\n";
    if(d<l)
    {
        node = u;d=l;
    }
    for(auto i:graph[u])
    {
        if(i!=p)
        dfs(i,u,l+1);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   node=0;d=0;
   int n;
   cin>>n;
   for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,0,1);
    d=0;
    dfs(node,0,1);
    cout<<d;
}