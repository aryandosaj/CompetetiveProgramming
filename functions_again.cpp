#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll dp[100001][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    ll arr[n];
    ll diff[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
            continue;
        else
        {
            diff[i - 1] = arr[i - 1] - arr[i];
        }
    }
}