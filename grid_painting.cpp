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
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,m,q;
       cin>>n>>m>>q;
    //    map<ll,ll>mp;
       ll ans=0;
       ll ans2=MAX;
       for(ll i = 0; i < q; i++)
       {
           ll x,y;
           cin>>x>>y;
           ans2 = min(ans2,y);
           ans = max(ans,y);
        //    if((mp[y]==0)&&(y!=0))
        //    {mp[y]=1;ans++;}
       }
       if(q!=0)
       cout<<ans-ans2<<"\n";
       else
       cout<<"0\n";
       
   }
}