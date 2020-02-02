#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll ans;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q,k;
    cin>>q>>k;
    ans=0;
    while(q--)
    {
        ll n,ans=0;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                ll g=__gcd(i,j);
                for(ll k=j+1;k<=n;k++)
                {
                    ans+=__gcd(g,k);
                    // cout<<i<<" "<<j<<" "<<k<<" "<<__gcd(g,k)<<"\n";
                }
            }
        }
        // cout<<six<<"\n";
        // cout<<fans<<" "<<p<<" "<<t<<" "<<(ans*power(t,MAX-2,MAX))%MAX<<"\n";
        // cout<<ans<<"\n";
        cout<<ans<<"\n";
    }

}