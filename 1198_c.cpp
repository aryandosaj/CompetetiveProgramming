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
   int pre[n+1];
   pre[0]=0;
   for(int i=1;i<=n;i++)
   {
       ll x;
       cin>>x;
       pre[i] = pre[i-1]+x;
   }
   ll q;
   cin>>q;
   while(q--)
   {
       ll l,r;
       cin>>l>>r;
       l--;
       cout<<(pre[r]-pre[l])/10<<"\n";
   }
}