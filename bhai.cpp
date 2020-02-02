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
   vll arr;
   map<ll,ll>mp;
   map<ll,ll>vis;
   for(int i = 0; i < 10; i++)
   {
       ll a;
       cin>>a;
       arr.push_back(a);
       mp[a]=1;

   }
   ll sum;cin>>sum;
   
   for(ll i = 0; i < arr.size() ; i++)
   {
       if(!vis[arr[i]])
       if(mp[arr[i]]&mp[sum-arr[i]])
       {
           vis[arr[i]]=1;
           vis[sum-arr[i]]=1;
           cout<<arr[i]<<" "<<sum-arr[i]<<"\n";
       }
   }
   
   
}