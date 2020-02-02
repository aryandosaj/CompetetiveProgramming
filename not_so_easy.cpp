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
vll graph[100001];
long long C(ll n, ll r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    ll i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
        ans%=MAX;
    }

    return ans;
}
ll nos(ll t)
{
    if(graph[t].size()==0)
    return 1;
    else
    {
        ll pro=1;
        
        for(ll i = 0; i < graph[t].size(); i++)
        {
            /* code */
            ll v = graph[t][i];
            pro*=C(graph[t].size(),graph[v].size()+1)*nos(v);
            pro%=MAX;

        }
        return pro;
        
    }
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
   ll t;
   cin>>t;
   cout<<C(5,2);
   while(t--)
   {
       ll n;
       cin>>n;
       
       for(ll i = 0; i < n-1; i++)
       {
           ll u,v;
           cin>>u>>v;
           graph[u].push_back(v);
       }
       cout<<nos(1)<<"\n";
       
   }
}