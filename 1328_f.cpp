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
map<ll, ll> mp;
map<ll, ll> mp1;
map<ll, ll> freq;
set<ll> s;
ll pre[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    f(1, n + 1)
            cin >>
        arr[i],
        freq[arr[i]]++, s.insert(arr[i]);
    sort(arr+1, arr + n+1);
    f(1, n + 1)
        pre[i] = pre[i - 1] + arr[i];
    ll sum = arr[1];
    ll c = 1;
    f(2, n + 1)
    {
        if (arr[i - 1] < arr[i])
            mp[arr[i]] = sum, mp1[arr[i]] = c;
        sum += arr[i];
        c++;
    }
    ll ans = 1e16;
    for (auto i : s)
    {
        ll f = freq[i];
        if (f >= k)
        {
            cout << "0";
            return 0;
        }
        ll req = k - f;
        ll a = 0;
        ll x1 = (i - 1) * mp1[i] - mp[i];
        ll x2 = (sum - mp[i] - i * freq[i]) - (n - mp1[i] - freq[i]) * (i + 1);
        // cout<<i<<" "<<x1<<" "<<x2<<" "<<mp[i]<<" "<<mp1[i]<<"\n";
        // First casse

        if (req <= mp1[i])
            a = x1 + req;
        else
            a = x1 + mp1[i] + x2 + (req - mp1[i]);
        ans = min(ans, a);
        a = 0;

        //Second case
        ll y = (n - mp1[i] - freq[i]);
        if (req <= y)
            a = x2 + req;
        else
            a = x1 + (req - y) + x2 + y;
        ans = min(ans, a);
    }
    cout<<ans;
}