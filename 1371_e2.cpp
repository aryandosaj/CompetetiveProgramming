#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
ll arr[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, p;
    cin >> n >> p;
    f(0, n) cin >> arr[i];
    sort(arr, arr + n);
    vll ans;
    ll l = 1, h = 1e9;
    ll st = 0;
    while (l <= h)
    {
        ll m = (l + h) / 2;
        ll c = m;
        ll flag = 0;
        fi(0, n)
        {
            ll num = upper_bound(arr, arr + n, c) - arr;
            c++;
            if (num - j == 0)
            {
                flag = 1;
                break;
            }
            if (num == n)
                break;
        }
        if (flag == 0)
            st = m,
            h = m - 1;
        else
            l = m + 1;
    }

    ll en = 0;

    l = st, h = 1e9;
    while (l <= h)
    {
        ll m = (l + h) / 2;
        ll c = m;
        ll flag = 0;
        fi(0, n)
        {
            ll num = upper_bound(arr, arr + n, c) - arr;
            c++;
            if (num - j >= p)
            {
                flag = 1;
                break;
            }
            if (num == n)
                break;
        }
        if (flag == 0)
            en = m,
            l = m + 1;
        else
            h = m - 1;
    }
    if (st == 0 || en == 0)
    {
        cout << "0\n\n";
        return 0;
    }
    cout << en - st + 1 << "\n";
    f(st, en + 1) cout << i << " ";
}