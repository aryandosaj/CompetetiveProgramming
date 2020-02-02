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
   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   ll n,p,k;
   cin>>n>>p>>k;
   ll arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   ll ans=0;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
           if(((arr[i]+arr[j])%p)==k)ans++;
       }
   }
   cout<<"Brute : "<<ans;
}