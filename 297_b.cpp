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
   ll n,m,k;
   cin>>n>>m>>k;
   ll alice[n];
   ll bob[m];
   
   for(ll i = 0; i < n; i++)
   {
       cin>>alice[i];
   }
   
   for(ll i = 0; i < m; i++)
   {
       cin>>bob[i]; 
   }
   sort(alice,alice+n);
   sort(bob,bob+m);
   ll j=m-1;
   if(n>m)
   {cout<<"YES";return 0;}
   for(ll i = n-1; i >=0; i--)
   {
       if(alice[i]>bob[j--])
       {
           cout<<"YES";return 0;
       }
   }
   cout<<"NO";
   
   
}