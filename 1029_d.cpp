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
   ll n,kk;
   cin>>n>>kk;
   string s[n];
   ll ans=0;
   for(ll i = 0; i < n; i++)
   {
       cin>>s[i];
   }
   
   for(ll i = 0; i < n; i++)
   {
       
       for(ll j = 0; j < n; j++)
       {
           if(i!=j)
           {
               string temp = s[i]+s[j];
               ll num=0;
               
               for(ll k = 0; k < temp.length(); k++)
               {
                   num*=10;
                   num+=temp[k]-48;
               }
               if(num%kk==0)
               ans++;
               
           }
       }
       
   }
   cout<<ans;
   
   
}