#include <bits/stdc++.h>
#define MAX 1000000007
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans=0;
    ans+=m;
    if(m>1)
    {
    if((k%2==0)&&(n==k))
    {
        ans+=power(m,n/2,MAX)-m;
    }
    if((k%2==1)&&(k<n))
    {
        ans+=(m*(m-1));
    }
    if((k%2==1)&&(k==n))
    {
        ans+=(power(m,n/2+1,MAX)-m);
    }
    
    }
    cout<<ans;
}