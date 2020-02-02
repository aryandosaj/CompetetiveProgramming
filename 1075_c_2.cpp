#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pint pair<int,int>
#define pb push_back
#define F first
#define S second
#define I insert
#define vint vector<int>
int power(int a, int b, int mod){ int c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   vint ver;
   for(int i=0;i<n;i++)
   {
       int a;
       cin>>a;
       ver.push_back(a);
   }
   ver.push_back(1e9);
   sort(ver.begin(),ver.end());
   vint hor;
   
   for(int i = 0; i < m; i++)
   {
       int a,b,y;
       cin>>a>>b>>y;
       if(a<2)hor.push_back(b);
   }
    hor.push_back(1e9);
   sort(hor.begin(),hor.end());
   int j=0;
   int ans=hor.size();
   for(int i = 0; i < ver.size(); i++)
   {
       
       for(; hor[j] < ver[i]; j++);
       ans = min(ans,(int)(i+(hor.size())-j-1));
       
   }
   cout<<ans;
   
   
}