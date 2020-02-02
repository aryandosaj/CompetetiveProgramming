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
vll graph[1005];
ll visit[1005];
ll flag=0;
void dfs(ll u)
{
    visit[u]=1;
    for(ll i = 0; i < graph[u].size(); i++)
    {

        ll v = graph[u][i];
        /* code */
        if((visit[v])&&(flag==0))
        {
            flag=1;
            cout<<v<<" ";
        }
        else
        dfs(v);
        
    }
    
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
   ll n;
   cin>>n;
   
   for(ll i = 1; i <= n; i++)
   {
       /* code */
       ll v;
       cin>>v;
       graph[i].push_back(v);
   }
   for(ll i = 1; i <=n; i++)
   {
       flag=0;
       for(ll j = 0; j < 1005; j++)
       {
           visit[j]=0;
       }
       dfs(i);
   }
   
   

}