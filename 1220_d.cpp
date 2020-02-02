#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
map<ll,ll>b;
map<ll,ll>vis;
ll n;
ll b[100005];
void dfs(ll u,ll p)
{
    vis[u]=1;
    for(int i=0;i<n;i++)
        {
            
            if(b[abs(b[i]-u)])
            {
                if(!vis[b[i]])dfs(b[i],u);
            }
        }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    
    for(int i=0;i<n;i++)
        cin>>arr[i],b[arr[i]]=1;

}