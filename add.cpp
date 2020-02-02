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
       ll a,b;
       cin>>a>>b;
       ll arr[40];
       ll brr[40];
       ll ans[40];
       for(ll i = 0; i < 40; i++)
       {
           arr[i]=0;brr[i]=0;ans[i]=0;
       }
       
       ll i=0;
       while(a>0)
       {
           arr[i]=a%2;
           a/=2;
           i++;
       }
       i=0;
        while(b>0)
       {
           brr[i]=b%2;
           b/=2;
           i++;
       }
       ll aaa=0;
       ll mul=1;
       for(ll i = 0; i < 40; i++)
       {
           ans[i]=(arr[i]+brr[i])%2;
           aaa+=ans[i]*mul;
           mul*=2;
       }
       cout<<aaa<<"\n";
       
   }
}