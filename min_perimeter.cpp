#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
#define x first
#define y second
#define point pair<ll,ll>
pair<ll,ll>arr[100005];
set<point>s;
ll n;
double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double rec(ll l,ll r)
{
    if(l==r)
    {
        return MAX;
    }
    else if(l+1==r)
    {
        return dist(arr[l],arr[r]);
    }
    ll m = (l+r)/2;
    double l1 = rec(l,m);
    double l2 = rec(m,r);
    double d = min(l1,l2);
    // cout<<fixed<<d<<"\n";
    auto start = s.lower_bound({arr[m].first-d,-MAX});
    auto stop = s.lower_bound({arr[m].first+d,+MAX});
    
    double ans=MAX;
    for(auto i = start;i!=stop;i++)
    {
        
        for(auto j = next(i);j!=stop;j++)
        {
            ans = min(ans,dist(*i,*j));
            
        }
        
    }
    cout<<ans<<"\n";
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
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i].x>>arr[i].y,s.insert(arr[i]);
    sort(arr,arr+n);
    cout<<rec(0,n-1);

}