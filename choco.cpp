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
   ll arr[n+1];
   
   for(ll i = 1; i <= n; i++)
   {
       cin>>arr[i];
   }
   
   ll q;
   cin>>q;
   ll c=0;
   
   for(ll i = 0; i < q; i++)
   {
       ll l,r;
       cin>>l>>r;
       if((c+arr[r])%2==0)
       {    
           cout<<"Sad\n";
           c+=arr[r];
       }
       else
       {cout<<"Happy\n";c+=arr[r];}
   }
   
}