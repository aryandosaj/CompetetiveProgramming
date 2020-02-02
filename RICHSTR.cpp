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
       ll n,q;
       cin>>n>>q;
       string s;
       cin>>s;
       map<char,int>mp;
       mp[s[0]]++;
       mp[s[1]]++;
       mp[s[2]]++;
       map<int,int>ans;
       for(auto j:mp)
        {
               if(j.second>=2)
                 ans[0]=1;
        }
       for(int i=3;i<n;i++)
       {
           mp[s[i-3]]--;
           mp[s[i]]++;
           for(auto j:mp)
           {
               if(j.second>=2)
                ans[i-2]=1;
           }
       }
       ll pre[n];
       pre[0]=ans[0];
       for(int i=1;i<n;i++)pre[i] = pre[i-1]+ans[i];
       while(q--)
       {
           ll l,r;
           cin>>l>>r;
           l--;r--;
           if(r-l+1<3)cout<<"NO\n";
           else
           {
               if(l==0)
               {
                   if(pre[r-2]>0)
                   cout<<"YES\n";
                   else
                   {
                       cout<<"NO\n";
                   }
                   
               }
               else
               {
                    if(pre[r-2]-pre[l-1]>0)
                    {
                        cout<<"YES\n";
                    }
                    else
                    cout<<"NO\n";
               }
               
               
           }
           
       }
   }
}