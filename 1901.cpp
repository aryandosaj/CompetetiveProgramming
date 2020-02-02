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
       ll n;string k;
       cin>>k>>n;
       queue<string>q;
       q.push(k);   
       unordered_map<string,ll>mp;
       mp[k]=1;
       ll c=1,y=0;
       while(!q.empty())
       {
           string u = q.front();q.pop();
           string s = u+u;
           for(ll i=0;i<s.length();i++)
           {
               for(ll j=0;j<s.length();j++)
               {
                   for(ll k=0;k<s.length();k++)
                   {
                       if((i!=j)&&(j!=k)&&(k!=i)){
                           string temp;temp.push_back(s[i]);
                           temp.push_back(s[j]);temp.push_back(s[k]);
                       if(!mp[temp])
                       {
                           q.push(temp);mp[temp]=1;c++;
                       }
                       }
                   }
               }
           }
           
       }
       cout<<c<<"\n";
   }
}