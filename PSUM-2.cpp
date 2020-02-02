#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 998244353
ll n,k,c;
ll crr[105];
ll val[105];
vll v[105];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>c>>k;
    for(int i=0;i<n;i++)cin>>crr[i]>>val[i];
    ll ans = 0;
    v[0].push_back(0);
    for(int i=0;i<n;i++)
    {
        for(int j = c - crr[i];j>= 0;j--)
        {
            for(int kk= 0 ;kk<v[j].size();kk++)
            {
                (ans += power((v[j][kk]+val[i])%MAX,k,MAX))%=MAX;
                v[j+crr[i]].push_back((v[j][kk] + val[i])%MAX);
            }
        }
    }
    cout<<ans;
}