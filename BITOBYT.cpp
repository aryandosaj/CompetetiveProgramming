#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
       n--;
       ll by = n/26;
       ll left = n%26;
       ll b=0,ni=0,bb=0;
       b = pow(2,by);
       if(left>=10)
       {
           bb=b;
           b=0;
       }
       else if((left>=2)&&(left<10))
       {
           ni=b;
           b=0;
       }
       cout<<b<<" "<<ni<<" "<<bb<<"\n";
   }
}