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
   ll n;
   cin>>n;
   vll v;
   unordered_map<ll,ll>mp;
   for(ll i=0;i<n;i++)
   {
       ll x;cin>>x;v.push_back(x);mp[x]++;

   }
   ll k=0;
    unordered_map<ll,ll>mp2;
   for(k;k<n;k++)
   {
       mp2[v[k]]++;
       if(mp[v[k]]==mp2[v[k]])
        {cout<<k+1;return 0;}


   }
}