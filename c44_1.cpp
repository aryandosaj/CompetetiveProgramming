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
    ll arr[n/2+1];
    arr[0]=0;
    ll ans_o=0,ans_e=0;
    for(ll i=1;i<=n/2;i++)
    {
        cin>>arr[i];
        
    }
    sort(arr,arr+n/2+1);
    for(int i = 1; i <= n/2; i++)
    {
        ans_e+=abs(2*i-arr[i]);
        ans_o+=abs(2*i-1-arr[i]);
    }
    cout<<min(ans_o,ans_e);
    
}