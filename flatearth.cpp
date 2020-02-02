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
struct dt{
    int x,val;
};
bool comp(dt a,dt b)
{
    return a.val>b.val;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   dt arr[100001];
   
   for(int i = 0; i < 100001; i++)
   {
       arr[i].x=i;
       arr[i].val=0;
   }
   
   int t;
   cin>>t;
   while(t--)
   {
       int n,l,r;
       cin>>n>>l>>r;
       map<int,int>mp;
       map<int,int>mp1;
       for(int i = 0; i < n; i++)
       {
           int x;
           cin>>x;
           arr[x].val+=x;
           mp[x]+=x;
       }
       sort(arr,arr+100001,comp);
       int ans=0;
       for(int i = 0; i < 100001; i++)
       {
           if(mp[arr[i].x]!=0)
           {
               ans+=mp[arr[i].x];
               mp[arr[i].x]=0;
               for(int j = 1; j <= r; j++)
               {
                   if(arr[i].x+j>100000)
                   break;
                   mp[arr[i].x+j]=0;
               }
               for(int j = 1; j <= l; j++)
               {
                   if(arr[i].x-j<0)break;
                   mp[arr[i].x-j]=0;
               }
               
           }
       }
       cout<<ans<<"\n";
       
   }
}