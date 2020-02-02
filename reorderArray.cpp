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
    map <ll,ll> mp;
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;

    }
    sort(arr,arr+n);
    ll c[n];
    c[0]=0;
    ll sub=0;
    for(ll i = 1; i < n; i++)
    {
        if((arr[i-1])<arr[i])
        {
            c[i]=c[i-1]+mp[arr[i-1]];
            
        }
        else
            c[i]=c[i-1];
        if(c[i]-sub>0)
        sub++;
    }
    cout<<sub;

    
}