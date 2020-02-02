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
   ll n;
   scanf("%lld",&n);
   ll arr[n];
   ll brr[n];
   map<ll,ll> mp;
   ll g=0;
   for(ll i = 0; i < n; i++)
   {
       scanf("%lld%lld",&arr[i],&brr[i]);
       g = __gcd(g,arr[i]*brr[i]);
   }
   if(g==1)
    {printf("-1");return 0;}
    else
    {
        ll num=max(__gcd(g,arr[0]),__gcd(g,brr[0]));
        while(num%2==0)
       {
           cout<<"2";return 0;
        num/=2;
       }
       
       for(int j = 3; j*j <= (num); j++)
       {
           while(num%j==0)
           {cout<<j;return 0;num/=j;}
       }
       if(num>2)
       cout<<num;
    }
}