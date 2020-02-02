#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    ll arr[n];
    map<ll,ll> mp;
    vector <ll> v;
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(mp[arr[i]]==0)
        {
            mp[arr[i]]++;
            v.push_back(arr[i]);
            if(arr[i]%2==1)
            v.push_back(arr[i]+1);
        }
    }
    sort(v.begin(),v.end());
    // for(ll i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    for(ll i = 0; i < v.size(); i++)
    {
        
        for(ll j = 0; j < n; j++)
        {
            if(arr[j]==v[i])
            {
                if(v[i]%2==0)
                arr[j]--;
                else
                arr[j]++;
            }
        }
        
    }
    
    for(ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
}