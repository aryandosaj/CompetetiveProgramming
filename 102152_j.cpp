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
       ll n,m;
       cin>>n>>m;
       unordered_map<ll,ll>mp;
       ll b=0;
       vll temp;
       for(ll i=0;i<n;i++)
       {
           
           for(ll j=0;j<m;j++)
           {
               
                   ll x;
                   cin>>x;temp.push_back(x);
                   if(mp[x]>0)mp[x]--,b++;
           }
           mp.clear();
           for(auto k:temp)mp[k]++;
           temp.clear();
       }
       cout<<b<<"\n";
   }
}