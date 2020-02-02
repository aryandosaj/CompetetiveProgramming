#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n,d;
    cin>>n>>d;
    ll arr[n];
    ll c=2;
    // map <ll,ll> mp1;
    // map <ll,ll> mp2;
    for(ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        // mp1[arr[i]]=1;
    }
    for(ll i = 0; i < n-1; i++)
    {
        if((arr[i+1]-arr[i]-2*d)==0)
        c++;
        else if(((arr[i+1]-arr[i]-2*d)>0))
        // cout<<c<<" ";
        c+=2;
    }
    cout<<c;
    
}