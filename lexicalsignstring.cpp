#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll bit[100005];
void insert(ll u,ll v)
{
    for(ll i=u;i<100005;i+=(i&-1))
    bit[i]+=v;
}
ll query(ll u)
{
    ll ans=0;
    for(int i=u;i>0;i-=(i&-i))
        ans+=bit[i];
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll p[n + 1];
    p[0]=0;
    ll pre[n+1];
    pre[0]=0;
    for (int i = 1; i <= n; i++)
        cin >> p[i],insert(i,p[i]);
    pair<ll, pair<ll, ll>> arr[k];
    
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
    }
    sort(arr, arr + n);
    for (int i = 0; i < k; i++)
    {
        ll l = arr[i].first;
        ll r = arr[i].second.first;
        ll c = arr[i].second.second;
        ll sum = query(r)-query(l-1);
        if(sum>=c){
            
        }
        ll req = c-sum;
        for(int )
    }
}