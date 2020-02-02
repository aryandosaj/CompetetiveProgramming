#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int a[1000005];
int b[1000005];
int mp[1000005];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {    
       
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=n;i++)
       cin>>a[i],mp[i]=-1;
       for(int i=1;i<=m;i++)
       cin>>b[i],mp[i]=-1;
       for(int i=1;i<=m;i++)
       {
           for(int j = i;j<=n;j+=i)
           {
               if(mp[j]==-1&&a[j]-b[i]<=0){mp[j]=i;}
           }
       }
       for(int i=1;i<=n;i++)
            cout<<mp[i]<<"\n";
   }
}