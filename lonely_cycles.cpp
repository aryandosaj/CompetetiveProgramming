#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
vll graph[200002];
ll visit[200002];
ll siz[200002];
map<ll,ll> mp;
stack <ll> st;
ll cy=1;
void dfs(ll u,ll p)
{
    visit[u]=1;
    st.push(u);
    for(ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if(v==p)
        continue;
        if(visit[v]==1)
        {
            while(st.top()!=v)
            {
                //cycle found
                mp[st.top()]=cy;
                st.pop();
            }
            mp[st.top()]=cy;
            st.pop();
            cy++;
        }
        else
        {
            siz[u]+=siz[v];
        }
        
    }

    
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,m;
       cin>>n>>m;
       
       for(ll i = 0; i < m; i++)
       {
           ll u,v;
           cin>>u>>v;
           graph[u].push_back(v);
           graph[v].push_back(u);
       }
       
   }
}