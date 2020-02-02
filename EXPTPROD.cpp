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
       ll n,k,kk;
       cin>>n>>k;
       kk=k;
       ll freq[n+1],ans[n+1],temp[n+1];
       for(ll i=0;i<=n;i++)freq[i]=0,ans[i]=0,temp[i]=0;
       for(ll i=0;i<n;i++){ll x;cin>>x;freq[x]++;}
       ans[1]=1;
       while(k>0)
       {
           if(k&1){
               for(ll i=0;i<=n;i++)temp[i]=0;
               for(ll i=0;i<n;i++)
               {
                   for(ll j=0;j<n;j++)
                   {
                       temp[(i*j)%n] = (temp[(i*j)%n] + (ans[i]*freq[j])%MAX)%MAX;
                   }
               }    
               for(ll i=0;i<=n;i++)ans[i]=temp[i];
               
           }
           for(ll i=0;i<=n;i++)temp[i]=0;
               for(ll i=0;i<n;i++)
               {
                   for(int j=0;j<n;j++)
                   {
                       temp[(i*j)%n] = (temp[(i*j)%n] + (freq[i]*freq[j])%MAX)%MAX;
                   }
               }
               for(ll i=0;i<=n;i++)freq[i]=temp[i];
           k/=2;
       }
       ll a=0;
       for(int i=0;i<n;i++)a=(a+i*ans[i])%MAX;
    //    cout<<a<<" ";
       ll den = power(n,kk,MAX);
       den = power(den,MAX-2,MAX);
       cout<<(a*den)%MAX<<"\n"; 
   }

}