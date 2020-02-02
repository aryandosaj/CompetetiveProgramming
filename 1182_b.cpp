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
   ll h,w;
   cin>>h>>w;
   string s[h];
   for(ll i=0;i<h;i++)cin>>s[i];
   ll r[h];
   
   ll rr=-1,cc=-1;
   for(ll i=0;i<h;i++)
   {
       ll c=0;
       for(ll j=0;j<w;j++)
       {
           if(s[i][j]=='*')c++;
       }
       if(c>1){rr=i;break;}
   }
   for(ll i=0;i<w;i++)
   {
       ll c=0;
       for(ll j=0;j<h;j++)
       {
           if(s[j][i]=='*')c++;
       }
       if(c>1){cc=i;break;}
   }
   ll c=0;
   for(ll i=0;i<h;i++)
   {
       for(ll j=0;j<w;j++)
       {
           if(s[i][j]=='*')c++;
       }
   }
   ll count=1;
   if(rr==-1||cc==-1){cout<<"NO";return 0;}
   if(cc==w-1){cout<<"NO";return 0;}
   if(rr==h-1){cout<<"NO";return 0;}
   if(s[rr][cc]=='.'){cout<<"NO";return 0;}
   ll d=0,u=0,l=0,ri=0;
   for(int i=rr+1;i<h;i++)
   {
       if(s[i][cc]=='*')count++,d=1;
       else break;
   }
   for(int i=rr-1;i>=0;i--)
   {
       if(s[i][cc]=='*')count++,u=1;
       else break;
   }
   for(int i=cc-1;i>=0;i--)
   {
       if(s[rr][i]=='*')count++,l=1;
       else break;
   }
   for(int i=cc+1;i<w;i++)
   {
       if(s[rr][i]=='*')count++,ri=1;
       else break;
   }
   if(l*ri*u*d==0){cout<<"NO";return 0;}
   if(count==c)cout<<"YES";else cout<<"NO";



}