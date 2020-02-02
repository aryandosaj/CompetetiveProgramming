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
vll v[10001];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        set<ll> s;
        for (int i = 0; i < 10001; i++)
            v[i].clear();
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % k)
                arr[i] *= k;
            while (arr[i] % k == 0)
            {
                v[i].push_back(arr[i]);
                s.insert(arr[i]);
                arr[i] /= k;
            }
            v[i].push_back(arr[i]);
            s.insert(arr[i]);
            sort(v[i].begin(), v[i].end());
            // for (auto j : v[i])
            //     cout << j << " ";
            // cout << "\n";
        }   
        ll ans = MAX;
        for (auto i : s)
        {
            ll c = 0, r = 0;
            for (ll j = 0; j < n; j++)
            {
                auto p = lower_bound(v[j].begin(), v[j].end(), i);
                if (p != v[j].end())
                {
                    r = max(r, (*p));
                    c++;
                }
                else
                    continue;
            }
            if (c == n)
            {
                // cout<<" "<<r<<" "<<i<<"--\n";
                ans = min(ans, r - i);
            }
        }
        cout << ans << "\n";
    }
}