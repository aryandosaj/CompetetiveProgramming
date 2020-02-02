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
int arr1[100005];
int arr2[100005];
int n;
int rec(int i, int f)
{
    if (i == n - 1)
        if (f)
            return 1;
        else
            return 0;
    int ans = MAX;

    if (arr1[i] < arr1[i + 1] && arr2[i] < arr2[i + 1])
        ans = min(ans, rec(i + 1, f));
    if (arr2[i] < arr1[i + 1] && arr1[i] < arr2[i + 1])
        ans = min(ans, rec(i + 1, 1 - f));
    if (f)
        return ans + 1;
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    cout << min(rec(0, 0), rec(0, 1));
}