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
   ll t;
   cin>>t;
   while(t--)
   {
       double a,b;
       cin>>a>>b;
       if(b==0){cout<<"1\n";continue;}
       if(a==0){cout<<"0.5\n";continue;}
       if(b<a/4)cout<<setprecision(15)<<(1-b/a)<<"\n";
       else
       {
           cout<<setprecision(15)<<((b+a/8)/(2*b))<<"\n";
       }
       
   }
}