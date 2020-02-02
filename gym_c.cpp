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
#define MAX 998244353
ll dp[1001][1001];
ll n,k;
ll arr[1001];
ll ans(ll n,ll k)
{
    if(k==-1)
    return 1;
    else if(n==-1)
    {
        return 0;
    }
    else if(dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    else
    {
        ll a = (arr[n]*ans(n-1,k-1))%MAX;
        ll b = ans(n-1,k);
        dp[n][k]=(a+b)%MAX;
        return dp[n][k];
    }
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k;
   map<ll,ll>mp;
   
   for(ll i = 0; i < 1001; i++)
   {
       
       for(ll j = 0; j < 1001; j++)
       {
           dp[i][j]=-1;
       }
       
   }
   
   for(ll i = 0; i < n; i++)
   {
       ll a;
       cin>>a;
        mp[a]++;
   }
//    ll arr[mp.size()];
   ll j=0;
   for (auto i:mp)
   {
       arr[j++]=i.second;
   }
   cout<<(ans(mp.size()-1,k-1));
}