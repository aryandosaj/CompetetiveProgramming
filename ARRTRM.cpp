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
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        set<ll> s;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            s.insert(arr[i]);
        }
        vector<ll> v;
        for (auto i : s)
            v.push_back(i);
        unordered_map<ll, ll> vis;
        map<ll, ll> mp;
        for (int i = 0; i < v.size(); i++)
        {
            if (vis[i] == 0)
                for (int j = i + 1; j < v.size(); j++)
                {
                    if (vis[j] == 0 && ((v[j] - v[i]) % (k + 1)) == 0)
                    {
                        vis[j] = 1;
                        v[j] = v[i];
                    }
                }
            mp[v[i]]++;
        }
        ll ss = mp.size();
        if (ss == 1)
        {
            cout << "YES\n";
            continue;
        }
        if (ss > 2)
        {
            cout << "NO\n";
            continue;
        }

        vector<ll> v2;
        v=v2;
        for (auto i : mp)
            v.push_back(i.second);
        sort(v.begin(), v.end());
        if ((v[0] > 1 && ss == 1) || (v[0] == 1 && ss == 2))
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}