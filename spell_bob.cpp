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
       string s1[2];
       cin>>s1[0]>>s1[1];
       map<char,ll>mp;
       ll flag=0;
       for(ll i = 0; i < 2; i++)
       {
           mp[s1[i][0]]++;
           for(ll j = 0; j < 2; j++)
           {
           mp[s1[j][1]]++;
               for(ll k = 0; k < 2; k++)
               {
                    mp[s1[k][2]]++;
                    if((mp['b']>=2)&&(mp['o']>=1))
                    {
                        cout<<"yes\n";
                        flag=1;
                        mp[s1[k][2]]--;
                        break;
                    }
                    mp[s1[k][2]]--;
               }
               mp[s1[j][1]]--;
               if(flag==1)
                   break;
           
           }
           mp[s1[i][0]]--;
           if(flag==1)
                   break;
       }
       if(flag==0)
       cout<<"no\n";
       mp.clear();
   }
}