#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    ll crr[m];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    ll j = 0;
    for (ll i = 0; i < m; i++)
    {
        cin >> crr[i];
    }
    for (ll i = 0; i < m; i++)
    {
        if (j <= n - 1)
            while (arr[j] > crr[i])
            {
                j++;
                if (j > n - 1)
                {
                    break;
                }
            }
        if (j > n - 1)
        {
            break;
        }
        j++;
        ans++;
        if (j > n - 1)
        {
            break;
        }
    }
    cout<<ans;
}