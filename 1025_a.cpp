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
   string s;
   cin>>s;
   map<char,ll>mp;
   if(n==1)
   {cout<<"YES";return 0;}
   for(int i = 0; i < s.length(); i++)
   {
       mp[s[i]]++;
   }
   for(auto i: mp)
   {
       if(i.second>=2)
       {
           cout<<"YES";return 0;
       }
   }
   cout<<"NO";
   
}