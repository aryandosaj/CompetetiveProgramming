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
#define ri second.first
#define le first
#define ind second.second

pair<ll, pair<ll, ll>> arr[200005];
vll lef[200005];
vll rig[200005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        ll l, r;
        cin >> l >> r;
        arr[i] = {l, {r, i}};
        lef[l].push_back(i);
        rig[r].push_back(i);
    }
    vll v;
    set<pair<ll, pair<ll, ll>>, greater<pair<ll, pair<ll, ll>>>> s;
    for (int i = 1; i <= 200000; i++)
    {
        for (auto j : lef[i])
            s.insert({arr[j].ri, {arr[j].le, arr[j].ind}});
        while (s.size() > k)
        {
            pair<ll, pair<ll, ll>> temp = *(s.begin());
            // cout<<i<<" "<<temp.le<<" "<<temp.ri<<"\n";
            v.push_back(temp.second.second);
            s.erase(temp);
        }
        for (auto j : rig[i])
            s.erase({arr[j].second.first, {arr[j].first, arr[j].second.second}});
    }
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i << " ";
}