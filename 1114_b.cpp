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
struct dt
{
    ll v, i;
};
vector<dt> arr;
vll b;
bool comp(dt a, dt b)
{
    return a.v > b.v;
}
unordered_map<ll, ll> mp;
unordered_map<ll, ll> visit;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        dt temp;
        cin >> temp.v;
        temp.i = i;
        arr.push_back(temp);
        b.push_back(temp.v);
    }
    sort(arr.begin(), arr.end(), comp);
    ll ans=0;
    for(ll i=0;i<(m*k);i++)
    {
        mp[arr[i].i]=1;
        ans+=arr[i].v;
    }
    ll c=0;
    ll u=1;
    vll p;
    for(ll i=0;i<b.size();i++)
    {
        if(mp[i]==1)
        {
            c++;
        }
        if(c==m)
        {p.push_back(i+1);c=0;u++;}
        if(u==k)break;
    }
    cout<<ans<<"\n";
    for(auto i:p)cout<<i<<" ";
}