#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin>>q;
    while(q--)
    {
        ll n,b;
        cin>>n>>b;

        ll num = (1ll<<b);
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(num&i)ans++;
        }
        cout<<ans<<"\n";
    }
}