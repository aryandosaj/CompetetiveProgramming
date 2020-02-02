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
map<ll,vll> graph;
map<ll,bool> visit;
ll n;
ll s=0;
ll flag=0;
void dfs(ll u)
{
    s++;
    visit[u]=1;
    ll t=s;
    map <ll,bool> v2;
    v2=visit;
    for(ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if(visit[v]) 
        continue;
        else
        {
            if(v<=u)
            {
                dfs(v);
                v2=visit;
                for(ll j = 0; j < graph[u].size(); j++)
                {
                    if(visit[graph[u][j]])
                    continue;
                    else if(v>u)
                    {dfs(graph[u][j]);if(flag==1)break;s=t;visit=v2;}
                }
            }
        }
    }
    if(s==n)
    flag=1;
    
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   ll arr[n];
   ll mm=MAX;
   for(ll i = 0; i < n; i++)
   {
       cin>>arr[i];
       mm = min(mm,arr[i]);
   }
   
   for(ll i = 0; i < n; i++)
   {
       
       for(ll j = i; j < n; j++)
       {
           if(__gcd(arr[i],arr[j])>1)
           {
               graph[arr[i]].push_back(arr[j]);
               graph[arr[j]].push_back(arr[i]);
           }
       }
   }
//    ll start=-1;
//    for(auto j:graph)
//    {
//        if(j.second.size()==1)
//        {
//            start = j.first;
//            break;
//        }
//    }
//    if(start==-1)
//    {cout<<"YES";return 0;}
   dfs(mm);
   if(flag==1)
   cout<<"YES";
   else
   cout<<"NO";
    
   
}