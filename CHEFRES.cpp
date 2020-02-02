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

struct st
{
    ll start,close;
};
bool comp(st a,st b)
{
    return a.start<b.start;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,m;
       cin>>n>>m;
       ll start[n],end[n];
       
       for(ll i = 0; i < n; i++)
       {
           cin>>start[i]>>end[i];
       }
        sort(start,start+n);
        sort(end,end+n);
        
        for(ll i = 0; i < m; i++)
        {
            ll x;
            cin>>x;
            auto p = upper_bound(end,end+n,x)-end;
            ll ind = p;
            if(ind==n)
            {
                cout<<"-1\n";continue;
            }
            if(start[ind]<=x)
            {
                cout<<"0\n";
            }
            else
            {
                cout<<(start[ind]-x)<<"\n";
            }

        }
        
       
   }
}