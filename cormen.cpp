#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    ll sum=0;
    ll tot_extra_walk = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(i==0)
        continue;
        sum = arr[i] + arr[i - 1];
        if (sum < k)
        {
            arr[i] += (k - sum);
            tot_extra_walk += (k - sum);
        }
    }
    cout << tot_extra_walk << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}