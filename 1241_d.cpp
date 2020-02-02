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
        ll n;
        cin >> n;
        ll arr[n+1];
        ll dp[n+1];
        ll a = 1;
        set<ll> s;
        pair<ll, ll> p[n + 1];
        map<ll, ll> mp;
        ll c = 1;
        for (int i = 0; i < n; i++)
            cin >> arr[i], s.insert(arr[i]);
        for (auto i : s)
            mp[i] = c++;
        s.clear();
        for (int i = 0; i < n; i++)
            arr[i] = mp[arr[i]], s.insert(arr[i]);
        for (int i = 0; i < n + 1; i++)
            p[i] = {MAX, 0};
        for (ll i = 0; i < n; i++)
            p[arr[i]].first = min(p[arr[i]].first, i), p[arr[i]].second = max(p[arr[i]].second, i);
        dp[1] = 1;
        vll v;
        for (auto i : s)
            v.push_back(i);
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (p[v[i]].second < p[v[i + 1]].first)
            {
                dp[v[i + 1]] = dp[v[i]] + 1;
            }
            else
                dp[v[i + 1]] = 1;
            a = max(dp[v[i + 1]], a);
        }
        c--;
        cout << c - a << "\n";
    }
}