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
bool compar(string s1,string s2)
{
    ll l =s1.length();
    
    for(ll i = 0; i < l; i++)
    {
        if(s1[i]!=s2[i])
        return false;
    }
    return true;
    
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   string s;
   cin>>s;
   ll l=s.length();
   string temp = s.substr(l-1,l);
   
   ll lps[l]={0};
   lps[0]=0;
   for(ll i = 1; i < l; i++)
   {

        if(s[lps[i-1]]==s[i])
        {
            lps[i]=lps[i-1]+1;
        }
        else if(lps[i-1]!=0)
        {
            ll ind=lps[lps[i-1]];
            while(1)
            {
                if(s[ind]==s[i])
                {
                    lps[i]=lps[ind]+1;break;
                }

                if(lps[ind]==0)
                break;
                ind = lps[ind];
            }
        }    
   }
vector <ll> ans;
ll ind = lps[l-1];
while(ind!=0)
{
    ans.push_back(ind);
    ind = lps[ind-1];
}
//    for(ll i = 0; i < l; i++)
//    {
//        if(s[i]==s[l-1])
//        {
//            ll ind=lps[l-i-1];
//            while(ind!=i)
//            {

//            }
//        }
//    }
   
   
   for(ll i = 0; i < l ; i++)
   {
       cout<<lps[i]<<" ";
   }
   
   
}