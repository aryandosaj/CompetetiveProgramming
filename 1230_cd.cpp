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
ll vis[7001];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll b[n];
    ll a[n];
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[i] = x;
        mp[x]++;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vll v;
    for (auto i : mp)
    {
        if (i.second > 1)
            v.push_back(i.first);
    }
    ll c = 0;
    for (auto i : v)
    {
        
        for (int j = 0; j < n; j++)
        {
            if (((a[j] ^ i) | i) == i)
            {
                if (vis[j] == 0)
                {
                    c += b[j];
                    vis[j] = 1;
                }
            }
        }
        
    }
    cout << c;
}