#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    ll c[n], cc[n];
    for (ll i = 0; i < n; i++)
        cin >> c[i], c[i] = c[i] * (n - i);
    sort(c, c + n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        x -= c[i];
        if (x >= 0)
            ans++;
    }
    cout << ans;
}