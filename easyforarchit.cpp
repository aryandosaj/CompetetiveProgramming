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

   int t;
   scanf("%d",&t);
   map<int,vint>mp;
   
   for(int i = 2; i < 1000001; i++)
   {
       int num=i;
       int d=0;
       if(num%2==0)d++;
       while(num%2==0)
       {
        num/=2;
       }
       
       for(int j = 3; j <= sqrt(num); j++)
       {
           if(num%j==0)d++;
           if(d>6)break;
           while(num%j==0)
           num/=j;
       }
       if(d>6)break;
       if(num>2)
       d++;
       mp[d].push_back(i);
       
   }
   
   while(t--)
   {
       int l,x,k;
       scanf("%d%d%d",&l,&k,&x);
        int p = lower_bound(mp[k].begin(),mp[k].end()+1,l) - mp[k].begin();
        if(x==0)
        {
            if(mp[k][p]==l)
            printf("-1\n");
            else
            printf("%d\n",l);continue;}
        if(mp[k].size()<=(p+x-1))
        printf("-1\n");
        else
        printf("%d\n",mp[k][p+x-1]);
   }
}