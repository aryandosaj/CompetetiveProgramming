#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 998244353
ll n,k,c;
ll crr[105];
ll val[105];
ll rec(ll i,ll sum,ll cost)
{
    if(i==n)
        return power(sum,k,MAX);
    ll s=0;
    if(c>=cost)
    s+=rec(i+1,sum,cost);
    if(c>=cost+crr[i])
    s+=rec(i+1,(sum+val[i])%MAX,cost+crr[i]);
    return s%MAX;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>c>>k;
    for(int i=0;i<n;i++)cin>>crr[i]>>val[i];
    cout<<rec(0,0,0);
}