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
#define point pair<ll, pair<ll, ll>>
#define x first
#define y second.first
#define z second.second
#define ind second.second
point arr[50004];
map<ll, vector<point>> mp;
map<ll, vector<pair<ll, ll>>> mp2;
vector<pair<ll, ll>> ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
        mp[arr[i].x].push_back({arr[i].y, {arr[i].z, i + 1}});
    }
    for (auto i : mp)
    {
        for (auto j : i.second)
        {
            mp2[j.first].push_back(j.second);
        }
        for (auto j : mp2)
        {
            for (int k = 0; k < j.second.size() - (j.second.size() & 1) ? 1 : 0; k += 2)
            {
                ans.push_back({j.second[k].second, j.second[k + 1].second});
            }
        }
    }
}