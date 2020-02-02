#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    map <ll,ll> distinct;
   
    
    ll n,m;
    cin>>n>>m;
    ll arr[n+1];
    ll dp[n+1];
    dp[0]=0;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        
    }
    for(int i = n; i >= 0; i--)
    {
        distinct[arr[i]]++;
        dp[i]=distinct.size();
    }
    

    for(int i = 0; i < m; i++)
    {
        ll l;
        cin>>l;
        cout<<(dp[l])<<"\n";
    }
    
    
}