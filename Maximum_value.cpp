#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
map <ll,ll> mp;
ll binarysearch(ll low, ll high, ll n, ll arr[])
{
    // cout<<low<<" "<<high<<"here";
    ll mid = (low + high) / 2;
    if (arr[mid] == n)
        return mid;
    if (low == high)
    {
        if (arr[low] > n)
        {
            return low;
        }
        else
        {
            return low + 1;
        }
    }
    if (arr[mid] > n)
        return binarysearch(low,mid, n, arr);
    else
        return binarysearch(mid+1, high, n, arr);
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll max_m = 0;
    ll m = 0;
    
    // cout<<binarysearch(0, n - 1, arr[n-1] / 2 + 1, arr);
    for (int i = n - 1; i >= 0; i--)
    {
        if(mp[arr[i]]!=0)
        continue;
        mp[arr[i]]=1;
        ll j = 2;
        while (arr[i] / j > max_m)
        {
            m = arr[i] % (arr[binarysearch(0, n - 1, arr[i] / j + 1, arr)]);
            // cout<<j<<" ";
            
            max_m = max(m, max_m);
            j++;
        }
    }
    cout<<max_m;
}