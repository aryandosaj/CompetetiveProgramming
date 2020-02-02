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
   string s,t;
   cin>>n>>s>>t;
   map<char,ll>mp1;
   map<char,ll>mp2;
   for(ll i = 0; i < n; i++)
   {
       mp1[s[i]]++;
       mp2[t[i]]++;
   }
   
   
   for(char i = 'a'; i <='z'; i++)
   {
       if(mp1[i]!=mp2[i])
       {
           cout<<"-1";return 0;
       }
   }
   vll v[200];
   ll pos[n];
   for(ll i = 0; i < n; i++)
   {
       v[t[i]].push_back(i);
   }
   
   for(ll i = 0; i < n; i++)
   {
       pos[n-i-1]=v[s[n-1-i]].back();
       v[s[n-1-i]].pop_back();
   }
   
//    for(ll i = 0; i < n; i++)
//    {
//        cout<<pos[i]<<" ";
//    }
   vll step;ll k=0;
   for(ll i = 0; i < n; i++)
   {
       
       for(ll j = 0; j < n-1; j++)
       {
           if(pos[j]>pos[j+1])
           {
               k++;
               step.push_back(j+1);
               ll temp=pos[j];
               pos[j]=pos[j+1];
               pos[j+1]=temp;
           }
       }
       
   }
   cout<<k<<"\n";
   
   for(ll i = 0; i < k; i++)
   {
       cout<<step[i]<<" ";
   }
   
   
   
   

   
   
   

}