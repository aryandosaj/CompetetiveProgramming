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
       string s;
       cin>>s;
       ll n = s.length();
       ll cl=1;
       vector<char>ans;
       ans.push_back(s[n-1]);
       ans.push_back(' ');
       string end = s[n-1]+"";
       for(ll i=n-2;i>=0;i--)
       {
           string temp="";
           for(ll j=0;j<cl;j++)
           temp+=s[i-j];
           reverse(temp.begin(),temp.end());
           if(temp.compare(end)>0)
            {
                if(n>4*cl)
                {
                    for(ll k=0;k<temp.length();k++)
                    {
                        ans.push_back(temp[k]);
                    }
                }
                else
                {
                    
                }
                
            }
           if()
           {
               ll j = 0;
               string temp="";
               while(j<i)
               {
                   ans.push_back(s[i+j]);

               }
           }
       }
       
   }
}