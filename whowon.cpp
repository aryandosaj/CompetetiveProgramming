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
       ll a=0,b=0;
       for(ll i=0;i<n;i++)
       {
           ll x;
           cin>>x;
           if(i&1)
           {
               if(x>3)b+=2;else a++;
           }
           else
           {
               if(x<4)a+=2;else b++;
           }
           
       }
        if(a>b)cout<<"Alice\n";else if(b>a)cout<<"Bob\n";else cout<<"Draw\n";
   }

}