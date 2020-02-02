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
   ll x1,x2,y1,y2;
   cin>>x1>>y1>>x2>>y2;
   if(y1==y2)
   {
        cout<<"Parallel to x-axis";
   }
   else if(y1==y2)
   {
        cout<<"Parallel to y-axis";

   }
   else cout<<"None"
}