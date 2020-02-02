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
   ll n;
   cin>>n;
   map<ll,ll>mp;
   mp[0]=0;
    while(n--)
    {
        ll l,r;
        cin>>l>>r;
        mp[l]++;mp[r+1]--;
    }
    ll pre=0;
    for(auto i:mp)
    {
        pre+=i.second;
        mp[i.first] = pre ;
        // cout<<i.first<<" "<<pre<<"\n";
    }
    ll q;cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        auto p = mp.upper_bound(x);
        p--;
        cout<<(*p).second<<"\n";
    }
}