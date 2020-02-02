#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
pair<ll,ll>arr[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll rt = sqrt(n)+1;
    ll a[rt+1];
    ll j=rt;
    for(int i=0;i<rt;i++)
    {
        if(j>n) 
        a[i]=j;
        j+=rt;
    }
    for(int i=0;i<q;i++)
        cin>>arr[i].first>>arr[i].second;



}