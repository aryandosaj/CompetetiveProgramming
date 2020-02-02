#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vll v,ans;
    ll num = (1<<n);
    unordered_map<ll,ll>mp;
    if(x>=num)
    {
        for(ll i=1;i<(1<<(n));i++)
        v.push_back(i);
    }
    else
    {
        for(ll i=1;i<(1<<n);i++)
        {
            if(i==x)continue;
            if(mp[i]==0)v.push_back(i),mp[x^i]=1;
        }
    }
    
    if(v.size()>0)ans.push_back(v[0]);
    for(ll j=1;j<v.size();j++)
    {
        ans.push_back(v[j]^v[j-1]);
    }
    cout<<ans.size()<<"\n";
    //  for(auto i:v)cout<<i<<" ";cout<<"\n";
    for(auto i:ans)cout<<i<<" ";

}
