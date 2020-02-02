#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
string pass;
vll graph[100000];
void create_pass(ll u)
{
    while(graph[u].size()>0)
    {
        ll v = graph[u].back();
        graph[u].pop_back();
        create_pass(v);
    }
    pass+=((char)u%256);
}
ll d[100000];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   string temp;
   for(ll i=1;i<=n;i++)
   {
       string s;cin>>s;
       ll u = s[0]*256 + s[1];
       ll v = s[1]*256 + s[2];
       d[u]++;d[v]--;
       graph[u].push_back(v);
   }
   ll start = -1,x=0;
   for(ll i=0;i<100000;i++)if(d[i]>=1)start = i,x++;
   if((x>1)||d[start]>1){cout<<"NO";return 0;}

   if(start==-1){
       for(ll i=0;i<100000;i++)
       {
           if(graph[i].size()>0){start=i;break;}
       }
   }
//    pass.push_back(char(start/256));
   create_pass(start);
   reverse(pass.begin(),pass.end());
   pass=(char)(start/256) + pass;
   if(pass.length()!=n+2){cout<<"NO";return 0;}
   else
   {
       cout<<"YES\n"<<pass;
   }
   



   
    

}