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
       double arr[n];
       double ans=0;
       for(ll i = 0; i < n; i++)
       {
           cin>>arr[i];
       }
       sort(arr,arr+n);
       int j=1;
       for(ll i = 0; i <= n-1; i++)
       {
           if(i==n-1)
           j--;
           if(j>25)
           {

               double temp=arr[i];
               int a2=j;
               while(a2>25)
               {
                   temp/=power(2,25,MAX);
                   a2-=25;
               }
                   temp/=power(2,a2,MAX);
                ans+=temp;
                j++;
                continue;
           }
           ans+=arr[i]/power(2,j,MAX);
           j++;
       }
       
    cout<<setprecision(15)<<ans<<"\n";       
       
   }
}