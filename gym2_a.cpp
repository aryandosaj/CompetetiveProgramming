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
   ll k;
   cin>>k;
   string s1,s2;
   cin>>s1>>s2;

   ll ans=0;
    ll c=0;
    ll c2=0;
    ll i_c=s1.length()-k;
   
   for(ll i = 0; i < s1.length(); i++)
   {
       if(s1[i]==s2[i])
       {
           if(c<k)
            ans++,c++;
       }
       else
       {
           if(c2<i_c)
           c2++,ans++;
       }
   }
   cout<<ans;
   

}