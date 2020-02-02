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
       ll n,q;
       cin>>n>>q;
       set<ll>s;
       map<ll,ll> mp;
       for(ll i=0;i<n;i++)
       {
           ll a;
           cin>>a;
           mp[i]=a;
           if(a)s.insert(a);
       }
       while(q--)
       {
           ll type;
           cin>>type;
           if(type==1)
           {
               ll p,v;
               cin>>p>>v;
               p--;
               if(mp[p])
               s.erase(mp[p]);
               if(v)
               s.insert(v);

           }
           else
           cout<<s.size()<<"\n";
       }
   }
}