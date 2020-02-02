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
       ll n;
       cin>>n;
       ll b[n];
       ll c[n];
       ll s=0,s1=0;
       ll f=0;
       for(int i=0;i<n;i++){
           cin>>b[i];s+=b[i];
           if(b[i]-1>=100)
            {
              f=1;  
            }
            c[i] = max(0ll,b[i]-1);
            s1+=c[i];
       }
       if(f||s<100)
       {
           cout<<"NO\n";
           continue;
       }
       if(s1>=100)
       {
           cout<<"NO\n";continue;
       }
       cout<<"YES\n";





       
   }
}