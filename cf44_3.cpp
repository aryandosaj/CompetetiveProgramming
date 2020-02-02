#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll diff_arr[100010];
ll arr[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k, l;
    ll m;
    cin >> n >> k >> l;
    m = n * k;
    for (ll i = 0; i < 100010; i++)
    {
        arr[i]=10000000000;
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 100010);
    ll vol = 0;
    for (ll i = 0; i < n; i++)
    {
        diff_arr[i] = arr[i] - arr[0];
        if (diff_arr[i] > l)
        {
            cout << "0";
            return 0;
        }
        
    }
    ll ind=m-1;
    for (ll i = 0; i < m; i++)
    {
        diff_arr[i] = arr[i] - arr[0];
        if(diff_arr[i]>l)
        {
            ind=i-1;
            break;
        }
    }   
    for(int i = 0; i <n-1; i++)
    {
        // cout<<(arr[ind-i])<<" ";
        vol+=(arr[ind-i]);
    }
    vol+=arr[0];
     
    cout << vol;
}