#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;

struct dt
{
    ll val;ll ind;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    dt arr[n];
    ll max_ind[n];
    ll min_ind[n];
    stack <dt> s;
    map <ll,ll> mp;
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i].val;
        arr[i].ind=i;
    }
    s.push(arr[0]);
    for(ll i=1;i<n;i++)
    {
        while(s.top().val>arr[i].val)
        {
            max_ind[s.top().ind]=i-1;
            s.pop();
            if(s.empty())
            break;
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        max_ind[s.top().ind]=n-1;
        s.pop();
    }


    s.push(arr[n-1]);
    for(ll i=n-2;i>=0;i--)
    {
        while(s.top().val>arr[i].val)
        {
            min_ind[s.top().ind]=i+1;
            s.pop();
            if(s.empty())
            break;
        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        min_ind[s.top().ind]=0;
        s.pop();
    }
    
    for(ll i = 0; i < n; i++)
    {
        if(mp[max_ind[i]-min_ind[i]+1]<arr[i].val)
        mp[max_ind[i]-min_ind[i]+1]=arr[i].val;
    }
    
    for(ll i = n-1; i >=1; i--)
    {
        if(mp[i]<mp[i+1])
        mp[i]=mp[i+1];
    }
    
    
    for(ll i = 1; i <=n; i++)
    {
        cout<<mp[i]<<" ";
    }
    
    

}