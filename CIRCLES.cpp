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
       double x1,y1,r1,x2,y2,r2;
       cin>>x1>>y1>>r1>>x2>>y2>>r2;
       double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
       if(d<=(r2-r1))
       {
           cout<<"NO\n";
       }
       else
       {
           cout<<"YES\n";
           double theta = atan((y2-y1)/(x2-x1));
           double p1x = x1+r1*cos(theta);

           double p1y = y1+r1*sin(theta);

            d = sqrt((p1x-x2)*(p1x-x2)+(p1y-y2)*(p1y-y2));
            if(d>r2)
            {
                cout<<setprecision(15)<<p1x<<" "<<p1y<<"\n";
            }
            else
            {
                p1x = x1-r1*cos(theta);

                p1y = y1-r1*sin(theta);
                cout<<setprecision(15)<<p1x<<" "<<p1y<<"\n";
            } 
       }
       
   }
}