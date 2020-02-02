#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n + 2];
    arr[0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    ll candies[n + 2];
    candies[0] = 0;
    candies[n + 1] = 0;
    for (ll i = 1; i <= n; i++)
    {
        if ((arr[i] <= arr[i - 1]) && (arr[i] <= arr[i + 1]))
        {
            candies[i] = 1;
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        if ((arr[i - 1] < arr[i]) && (arr[i] <= arr[i + 1]))
            candies[i] = candies[i - 1] + 1;
    }
    // for (auto i : candies)
    //     cout << i << " ";
    //     cout<<"\n";
    for (ll i = n; i >= 1; i--)
    {
        if ((arr[i - 1] >= arr[i]) && (arr[i] > arr[i + 1]))
            candies[i] = candies[i + 1] + 1;
    }
    for (auto i : candies)
        ;

    // cout<<"\n";
    for (ll i=1;i<n+1;i++)
    {
        if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
        candies[i] = max(candies[i - 1], candies[i + 1]) + 1;
    }
    ll ans = 0;
    for (auto i : candies)
        ans += i;
    cout << ans;
}