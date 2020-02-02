#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
double cur[5001],nxt[5001];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n,T;
   cin>>n>>T;
   double ans=0;
   cur[0]=1;
   for(ll i=0;i<n;i++)
   {
       double p;ll t;
       cin>>p>>t;
       p/=100;
       double khatam = pow(1-p,t);
       double s=0;
       for(ll j=0;j<=T;j++)
       {    
           double y=0;
           if(j>=t)
               y = khatam*cur[j-t];
            nxt[j]=y+p*s;
            ans+=nxt[j];
            s = s*(1-p) + cur[j] - y;
       }
       swap(cur,nxt);
   }
   cout<<setprecision(15)<<ans;
}