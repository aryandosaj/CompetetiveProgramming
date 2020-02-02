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
       string s;
       cin>>s;
       
       for(ll i = 0; i < n-1; i+=2)
       {
           char temp=s[i];
           s[i]=s[i+1];
           s[i+1]=temp;
           s[i]=97*2+25-s[i];
           s[i+1]=97*2+25-s[i+1];
       }
       if(n%2==1)
       s[n-1]=97*2+25-s[n-1];
       cout<<s<<"\n";
       
   }
}