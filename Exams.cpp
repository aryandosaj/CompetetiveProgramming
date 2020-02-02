#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct dt
{
    ll v;
    ll ind;
};
bool comp(dt a,dt b)
{
    return a.ind<b.ind;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n,m;
    cin>>n>>m;
    ll d[n+1];
    ll a[m+1];
    dt last_occur[m+1];
    last_occur[0].v=0;
    last_occur[0].ind=0;
    a[0]=0;
    for(int i = 1; i <= n; i++)
    {
        cin>>d[i];
        last_occur[d[i]].ind=i;
        last_occur[d[i]].v=d[i];
    }
    sort(last_occur,last_occur+m+1,comp);
    for(int i = 1; i <= m; i++)
    {
        cin>>a[i];
    }
    ll day=0;
    ll req=0;
    for(int i = 1; i <= m; i++)
    {
        req+=a[last_occur[i].v];
        cout<<last_occur[i].v<<"\n";
        day=last_occur[i].ind-i-1-1;
        if(req>day)
        {
            cout<<"-1";
            return 0;
        }
        
    }
    

    
}