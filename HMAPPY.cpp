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
struct dt{
    ll a,b,ab;
};
bool comp(dt a,dt b)
{
    return a.ab<b.ab;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n;ll m;
   cin>>n>>m;
   ll a[n],b[n];
   dt arr[n];
   
   for(ll i = 0; i < n; i++)
   {
       cin>>a[i];
       arr[i].a=a[i];
   }
   
   for(ll i = 0; i < n; i++)
   {
       cin>>b[i];
       arr[i].b=b[i];
       arr[i].ab=a[i]*b[i];
   }
    // sort(arr,arr+n,comp);
    ll l=0,r=1e18;
    ll mid,ans=0;
    ll final_ans=0,temp2=0;
    ll cost=0,ans_cost=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        temp2=0;
        cost=0;
        // cout<<mid<<"\n";
        for (ll i=0;i<n;i++)
        {
            ll temp= arr[i].ab-mid;
           
            if(temp>=0)
            {
                ll z = ceil(((double)temp)/((double)arr[i].b));
                temp2 = max(temp2,arr[i].ab-z*arr[i].b);
                cost+=z;
            }
            // cost+=ceil((arr[i].ab-arr[mid].ab)/arr[i].b);
        }
        
        if(cost<=m)
        {
            r=mid-1;ans = mid;ans_cost=cost;final_ans=temp2;
        }
        else
        {
            l=mid+1;
        }
    }
    
    cout<<final_ans<<"\n";
   
   

}