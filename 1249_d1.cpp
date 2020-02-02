#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int a[202];
int vis[202];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    pair<ll, pair<ll, ll>> arr[n];
    vll ans;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second.first;
        arr[i].second.second = i + 1;
        for (int j = arr[i].first; j <= arr[i].second.first; j++)
            a[j]++;
    }
    
    int flag = 0;
    for (int i = 0; i <= 200; i++)
    {
        ll ind = -1, mr = 0;
        while (a[i] > k)
        {
            flag = 1;
            for (ll j = 0; j < n; j++)
            {
                if (vis[j])
                    continue;
                if (arr[j].first <= i && arr[j].second.first >= i)
                {
                    if (mr < arr[j].second.first)
                    {
                        mr = arr[j].second.first;
                        ind = j;
                    }
                }
            }

            for (int j = arr[ind].first; j <= arr[ind].second.first; j++)
                a[j]--;
            vis[ind] = 1;
            mr=0;
            ans.push_back(arr[ind].second.second);
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
}