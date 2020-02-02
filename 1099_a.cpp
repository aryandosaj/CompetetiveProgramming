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
   ll w,h,u1,d1,u2,d2;
   cin>>w>>h>>u1>>d1>>u2>>d2;
   while(h!=0)
   {
       w+=h;
       if(h==d1) w-=u1;
       if(h==d2) w-=u2;
       w = max((ll)0,w);
       h--;
   }
   cout<<w;
}