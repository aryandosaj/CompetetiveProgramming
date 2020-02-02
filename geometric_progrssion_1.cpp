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
    ll visit[n];
    
    map<ll, ll> num_after[n];
    map<ll, ll> num_before[n];
    
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
        cin >> arr[i];
        // num_before[0][arr[i]]++;
        if(i==0)
        {
            num_before[i][arr[i]]++;
            continue;
        }
        num_before[i]=num_before[i-1];
        num_before[i][arr[i]]++;
    }
    num_after[n - 1][arr[n - 1]]++;
    for (int i = n - 2; i >= 0; i--)
    {
        num_after[i] = num_after[i + 1];
        num_after[i][arr[i]]++;
    }
    ll a = 0;
    if (k == 1)
    {

        for (ll i = 0; i < n; i++)
        {
            if (visit[arr[i]] == 1)
                continue;
            ll num = num_after[0][arr[i]];
            visit[arr[i]] = 1;
            a += (num * (num - 1) * (num - 2)) / 6;
        }
        cout << a;
        return 0;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if((arr[i])%k==0)
        {
            ans+=(num_before[i][arr[i]/k]*num_after[i][arr[i]*k]);
        }
    }
    cout << ans;
}