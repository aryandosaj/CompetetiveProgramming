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
   unordered_map<ll,ll>m1;
   unordered_map<ll,ll>m2;
   vll v;
   set<ll>s;
   for(int i=1;i<=m;i++)
   {
       ll x;
       cin>>x;
       v.push_back(x);
   }
   reverse(v.begin(),v.end());
    
   ll ans=0;
   for(auto i:v)
   {
    ll a=0;
    s.insert(i);
    // if(m1[i])a++;
    if(m1[i-1])a++;
    if(m1[i+1])a++;
    ans= ans+a-m2[i];
    m2[i]=a;

    //    cout<<i<<" "<<s.size()<<" "<<" "<<ans<<"\n";
    m1[i]=1;
   }
   ans = n+(n-1)*2-ans-s.size();
   cout<<ans;
}