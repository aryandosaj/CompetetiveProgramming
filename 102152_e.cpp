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
   ll t;
   cin>>t;
   while(t--)
   {
       string s,c,p;ll n,m;
       cin>>n>>m>>s>>c>>p;
       unordered_map<ll,set<ll>>mp;
       for(ll i=0;i<n;i++)mp[s[i]].insert(c[i]-'0');
       ll ans=0,flag=0;
       for(ll j=0;j<m;j++)
            if(mp[p[j]].empty()){flag=1;break;}else
            {
                ans+=*mp[p[j]].begin();
            }
        if(!flag)cout<<ans<<"\n";else
        {
            cout<<"-1\n";
        }
        
   }
}