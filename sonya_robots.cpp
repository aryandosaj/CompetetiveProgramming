#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    ll n;
    cin>>n;
    ll arr[n];
    int mp1[100001];
    map<ll,ll> mp;
    
    for(ll i = 0; i < 100001; i++)
    {
        mp1[i]=0;
    }
    ll dis_num_after[n];
    dis_num_after[n-1]=0;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // mp1[arr[n-1]]=1;
    // cout<<"here";

    for(int i =n-2;i>=0;i--)
    {
        
        if(mp1[arr[i+1]]==0)
        {
            mp1[arr[i+1]]=1;
        

            dis_num_after[i]=dis_num_after[i+1]+1;
        }
        else
            dis_num_after[i]=dis_num_after[i+1];
    }
    ll ans=0;
    for(int i = 0; i < n; i++)
    {
        if(mp[arr[i]]==0)
        {
            mp[arr[i]]=1;
            ans+=dis_num_after[i];
        }
      
    //    cout<<dis_num_after[i]<<" ";
    }
    cout<<ans;
    
}