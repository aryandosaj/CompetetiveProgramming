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
    cin >> n;
    ll arr[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            /* code */
            cin >> arr[i][j];
        }
    }
    // cout<<"here";
    ll krr[n + 1];
    for (ll i = n; i > 0; i--)
    {
        cin >> krr[i];
    }
    ll ans[n + 1];
    // cout<<"her";
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][krr[k]] + arr[krr[k]][j]);
            }
        }
        ans[k] = 0;
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= k; j++)
                ans[k] += arr[krr[i]][krr[j]];
        }
    // cout << "here";
    for (int i = n; i > 0; i--)
    {
        cout << ans[i] << " ";
        /* code */
    }
}