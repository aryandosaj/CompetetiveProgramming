#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll dp[1000][50][50];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   string a,s,t;
   cin>>a>>s>>t;
   for(ll i=0;i<a.length();i++)
   {
       if(i==0)
       {
           
       }
   }

}