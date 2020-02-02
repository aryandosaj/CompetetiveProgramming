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
       ll n;
       cin>>n;
       ll stu[n];
       map<ll,ll>mp;
       for(ll i = 0; i < n; i++)
       {
           cin>>stu[i];
       }
       
       for(ll i = 1; i <= n; i++)
       {
           ll x;
           cin>>x;
           mp[x]=i;
       }
       priority_queue<ll>pq;
       map<ll,ll>mp2;
       for(ll i = 0; i < n; i++)
       {
           mp2[mp[i]]=1;
           auto p = mp2.lower_bound(mp[i]);
           
       }
       
       
   }
}