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
ll grid[17][17];
ll n;
ll dp[17][17];
unordered_map <ll,unordered_map<ll,ll>>vis;
ll dfs(ll ui,ll uj)
{
    if(vis[ui][uj]==1)
    {
        return dp[ui][uj];
    }
    else
    {
        
        
        
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
       cin>>n;
       for(ll i = 0; i < n; i++)
       {
           for(ll j = 0; j < n; j++)
           {
               dp[i][j]=-1;
               cin>>grid[i][j];
           }
       }
        dfs(-2,-2);
       
   }
}