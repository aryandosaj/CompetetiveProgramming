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
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
    ll n,x;
    cin>>n>>x;
    ll arr[n];
    ll brr[n];
    map<ll,ll> mp1;
    map<ll,ll> mp2;
    ll ans=-1;
    ll flag=0;
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(mp1[arr[i]]==0)
        mp1[arr[i]]=1;
        else 
        {
            ans=0;
            flag=1;
        }
        brr[i]=arr[i]&x;
        
    }
    if(ans==-1)
    {
        
        for(ll i = 0; i < n; i++)
        {
            if((mp1[brr[i]]==1)&&(brr[i]!=arr[i]))
            {
                ans=1;
                break;
            }
        }

        
    }
    if(ans==-1)
    {
        for(ll i = 0; i < n; i++)
        {
            if(mp2[brr[i]]==0)
            mp2[brr[i]]=1;
            else
            {
                ans=2;
                break;
            }
        }

    }
    cout<<ans;
    
}