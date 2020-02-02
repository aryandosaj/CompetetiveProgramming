#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n,q;
    cin>>n>>q;
    ll arr[n];
    ll d[n];
    
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
        d[i]=0;
    }
    sort(arr,arr+n);
    for(int i = 0; i < q; i++)
    {
        ll l,r;
        cin>>l>>r;
        l--;r--;
        d[l]++;
        if(r<n-1)
        d[r+1]--;

    }
    ll ans=0;
    for(int i = 0; i < n; i++)
    {
        if(i!=0)
        d[i]+=d[i-1];
        
        
    }
    sort(d,d+n);
    for(int i = 0; i < n; i++)
    {
        
        ans+=d[i]*arr[i];
        
    }
    cout<<ans;
    
    

}