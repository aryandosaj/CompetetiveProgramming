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
       ll arr[n];
       for(ll i = 0; i < n; i++)
       {
           cin>>arr[i];
       }
       if(n%2==1)
       {
           cout<<"NO\n";continue;
       }
       else
       {
           ll flag=0;
           for(ll i = 0; i < n/2; i++)
           {
               if((arr[i]==-1)||(arr[n/2+i]==-1))
               {
                   if(arr[i]==arr[n/2+i])
                   {
                       arr[i]=1;
                       arr[n/2+i]=1;
                   }
                   else if(arr[i]==-1)
                   arr[i]=arr[n/2+i];
                   else
                   arr[n/2+i]=arr[i];
                   continue;
               }
               else
               {
                   if(arr[i]!=arr[n/2+i])
                   {
                       cout<<"NO\n";flag=1;break;
                   }
               }
           }
           if(flag==1)
           continue;
           else
           {
               cout<<"YES\n";
               
               for(ll i = 0; i < n; i++)
               {
                   cout<<arr[i]<<" ";
               }
               cout<<"\n";
               
           }
           
       }

       
   }
}