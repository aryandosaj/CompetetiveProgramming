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
#define MAX 100000000000000007
ll dp[1000][2000];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,k,p;
   cin>>n>>k>>p;
   ll people[n],keys[k];
   
   for(ll i = 0; i < n; i++)
   {
       cin>>people[i];
   }
   
   for(ll i = 0; i < k; i++)
   {
       cin>>keys[i];
   }
   sort(people,people+n);
   sort(keys,keys+k);
   
   for(ll i = 0; i < n; i++)
   {
       
       for(ll j = 0; j < k; j++)
       {
           dp[i][j]=abs(people[i]-keys[j])+abs(p-keys[j]);

       }
       
   }
   ll temp=0;
   ll ans=MAX;
   for(ll i = 0; i <= k-n; i++)
   {
       
       for(ll j = 0; j < n; j++)
       {
           temp=max(temp,dp[j][j+i]);
       }
        ans = min(ans,temp);
       temp=0;
   }
   cout<<ans;
   

   
}