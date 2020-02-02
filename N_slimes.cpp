#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAX 1e17
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int x;
    cin >> x;
    cout << x << "Fuck\n";

    // cin.tie(0);
    // ll n;
    // cin >> n;
    // ll arr[n];
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // ll ans = 0;
    // ll mm = MAX, mm_i, mm_k;
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     ll k;
    //     for (ll j = 0; j < n - 1 - i; j++)
    //     {
    //         k = j + 1;
    //         if ((arr[j] + arr[k]) < mm)
    //         {
    //             mm = arr[j] + arr[k];
    //             mm_i = j;
    //             mm_k = k;
    //         }
    //     }

    //     arr[mm_i] = mm;
    //     arr[mm_k] = -1;
    //     ll o = 0;
    //     for (ll r = 0; r < n; r++)
    //     {
    //         if (arr[r] != -1)
    //         {
    //             arr[o] = arr[r];
    //             o++;
    //         }
    //     }
    //     ans += mm;
    //     mm = MAX;
    //     // for (ll h = 0; h < n; h++)
    //     //     cout << arr[h] << " ";
    //     // cout << "\n";
    // }
    // cout << ans;
}