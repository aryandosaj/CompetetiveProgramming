#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007

int rec(int n)
{
  if(n==1)return 1;
  if(n&1)
  {
    return 2*(rec((n-1)/2))+1;
  }
  else
  {
    return 2*(rec(n/2))-1;
  }
  
}
// int r(int n)
// {
//   if(n==0)return 0;
//   if(n==1)return 0;
//   if(n&1)
//   {
//     return 2*(r(n/2)+1);
//   }
//   else
//   {
//     return 2*(r(n/2));
//   }
  
// }

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   cout<<rec(n-1)+1<<"\n";
  //  cout<<r(n);

}