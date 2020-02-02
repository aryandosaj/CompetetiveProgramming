#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
ll arr[1001][1001];
unordered_map<ll, unordered_map<ll, ll>> vis;
ll n,m,c;
void dfs(ll ux,ll uy)
{
    vis[ux][uy]=1;if(arr[ux][uy]==1)c++;
    for(ll i=-1;i<2;i++)
    {
        for(ll j=-1;j<2;j++)
        {
            ll vx =  ux+i,vy = uy+j;
            if(abs(i+j)==1)
            {
                if((vx>=0)&&(vx<n)&&(vy<m)&&(vy>=0))
                {
                    if((!vis[vx][vy])&&(arr[vx][vy]))
                        dfs(vx,vy);
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll ans=0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            c=0;
            if(!vis[i][j]){
                dfs(i,j);ans = max(ans,c);
            }

        }
    }
    cout<<ans;
}
