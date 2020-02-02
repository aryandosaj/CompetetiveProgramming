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
   ll n;
   cin>>n;
   double arr[n];
   double m=0;
   int flag=0;
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i]; 
       if(arr[i]==1)
       flag=1;
   }
   if(flag)
   {cout<<"1";return 0;}
   sort(arr,arr+n);
   double ans=0;
   double s=0;
   double c=1;
   int j=n-1;
   while((s<1)&&(j>=0))
   {
       c*=(1-arr[j]);
       s+=(arr[j])/(1-arr[j]);
       j--;
   }
   cout<<setprecision(15)<<(c*s);
   
}