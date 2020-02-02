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
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<arr[(n-1)/2];
}