#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
#define vpll vector<pll>

ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
int main()
{
    ll n,b;
    cin>>n>>b;
    ll arr[n];
    ll oe=0;
    vector<ll> v;
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        
        if((oe==0)&&(i!=0))
        {
            v.push_back(abs(arr[i]-arr[i-1]));
        }
        if(arr[i]%2==0)
        oe--;
        else
        oe++;

    }
    sort(v.begin(),v.end());
    ll ans=0;
    
    for(ll i = 0; i < v.size(); i++)
    {
        // cout<<v[i]<<" ";
        if(v[i]<=b)
        {
            ans++;
            b-=v[i];
        }
        else
        break;

    }
    cout<<ans;
    
    
}