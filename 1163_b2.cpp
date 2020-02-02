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
    ll n;
    cin >> n;
    ll arr[n];
    unordered_map<ll, ll> f;
    unordered_map<ll, ll> ff;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        f[arr[i]]++;
        ff[f[arr[i]]]++;
        if (f[arr[i]] != 1)
        {
            ff[f[arr[i]] - 1]--;
            if (ff[f[arr[i]] - 1] == 0)
            {
                ff.erase(f[arr[i]] - 1);
            }
        }
        if (ff.size() == 2)
        {
            vll first, second;
            for (auto j : ff)
            {
                first.push_back(j.first);
                second.push_back(j.second);
            }
            if ((first[0] * second[0] == 1) || (first[1] * second[1] == 1))
            {
                ans = i + 1;
            }
            else
            {
                if (abs(first[0] - first[1]) == 1)
                {
                    if ((first[0] > first[1]) && (second[0] == 1))
                        ans = i + 1;
                    else if ((first[1] > first[0]) && (second[1] == 1))
                        ans = i + 1;
                }
            }
        }
        if ((ff.size() == 1) && (f.size() == 1))
            ans = i + 1;
        else if (ff.size() == 1)
        {
            ll x;
            for (auto j : ff)
                x = j.first;
            if (x == 1)
                ans = i + 1;
        }
        //     for (auto j : ff)
        //         cout << j.first << " " << j.second << "\n";
        // cout<<"\n";
    }
    cout << ans;
}