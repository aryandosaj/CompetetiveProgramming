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
   ll n,k;
   cin>>n>>k;
   ll arr[n];
   map<ll,ll> mp2;

   vll d;
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i];     
       mp2[arr[i]]=1;
   }
   ll num=k;
   map<ll,ll> mp;
   while(num%2==0)
   {
       mp[2]++;
       num/=2;
   }
   
   for(ll i = 3; i <= n/2; i+=2)
   {
       while(num%i==0)
       {
           mp[i]++;
           num/=i;
       }
   }
   if(num>0)
    mp[num]++;
    for(auto i:mp)
    {
        if(!mp2[power(i.first,i.second,MAX)])
        {cout<<"NO";return 0;}

    }
    cout<<"YES";
   

   
}