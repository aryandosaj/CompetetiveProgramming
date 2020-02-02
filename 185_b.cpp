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
   double s,a,b,c;
   cin>>s>>a>>b>>c;
   if(a+b+c>0)
    cout<<setprecision(20)<<(a*s)/(a+b+c)<<" "<<(b*s)/(a+b+c)<<" "<<(c*s)/(a+b+c)<<" ";
    else cout<<"0 0 0";
}