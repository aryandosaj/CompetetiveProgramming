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
ll arr[1000006];
ll a[1000006];
ll temp[1000006];
ll merge(ll left, ll mid, ll right)
{
    ll i = left;
    ll j = mid;
    ll k = left;
    ll inv_count = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}
ll invcnt(ll low, ll high)
{
    if (low >= high)
        return 0;
    ll mid = (low + high) / 2;
    ll c1 = invcnt(low, mid);
    ll c2 = invcnt(mid + 1, high);
    ll ret = c1 + c2 + merge(low, mid + 1, high);
    // cout<<low<<" "<<high<<" "<<ret<<"\n";
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        while (q--)
        {
            ll k;
            cin >> k;
            for (int i = 0; i < n; i++)
                arr[i] = a[i] ^ k;
            cout << invcnt(0, n - 1) << "\n";
        }
    }
}