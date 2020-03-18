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
ll pre[10000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    if (n == 1)
    {
        if (m == 0)
        {
            cout << "1";
            return 0;
        }
        cout << "-1\n";
        return 0;
    }
    f(1, 5001)
        pre[i] = pre[i - 1] + (i - 1) / 2;

    ll ind = upper_bound(pre, pre + 5001, m) - pre;
    ind--;
    ll r = m - pre[ind];
    ll last = 2 * (ind - r);
    ll next = 2 * (last + 1);
    vll ans;
    f(1, ind + 1) ans.pb(i);
    ll rem;
    if (r)
        ans.pb(last),
            rem = n - (ind + 1);
    else
        rem = n - ind;
    if (rem >= 0)
    {
        f(1, rem + 1)
        {ll x=next * (2 * i - 1);
        if(x&1);else x++;
            ans.pb(x);}
        for (auto i : ans)
            cout << i << " ";
    }
    else
        cout << "-1";
}