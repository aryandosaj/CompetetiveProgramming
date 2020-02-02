#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll bit[100005]={0};
ll query(ll x)
{
    ll r = 0;
    for(ll i=x;i>=1;i-=i&(-i)) r+=bit[i];
    return r;
}
void update(ll x,ll val)
{
    for(ll i=x;i<100005;i+=i&(-i))bit[i]+=val;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   ll q;ll sum=0;
   cin>>n>>q;
   for(ll i=1;i<100005;i++) update(i,1);
   for(ll i=0;i<q;i++)
   {
       ll e,x;
       cin>>e>>x;
       if(e==1)
       {
           update(1,-1);
       }
       else if(e==2)
       {
           update(x,-1);

       }
       else
       {
           sum+=query(x);
       }
   }
   cout<<sum;
}   