#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,m;
   cin>>n>>m;
   vll b,g;
   ll ma = 0,mi = MAX;
   for(ll i=0;i<n;i++)
   {
       ll x;
       cin>>x;
       ma = max(x,ma);
       b.push_back(x);
   }
   for(ll i=0;i<m;i++)
   {
       ll x;
       cin>>x;
       mi = min(mi,x);
       g.push_back(x);
   }
   if(mi<ma){cout<<"-1";return 0;}
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    sort(g.begin(),g.end());
    ll ans=0;
    for(ll i=0;i<g.size();i++)
        ans+=g[i];
        // cout<<ans;
    if((n==1)&&(b[0]!=g[0])){cout<<"-1";return 0;}
    if(b[0]==g[0])
    { 
        for(ll i=1;i<n;i++)
        ans+=b[i]*m;
    }
    else
    {
        ans+=b[0];
        for(ll i=2;i<n;i++)
        ans+=b[i]*m;
        ans+=b[1]*(m-1);
    }
    cout<<ans;
    

}