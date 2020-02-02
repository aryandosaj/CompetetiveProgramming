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
    ll c = 0;
    vll v;
    vll vc;
    map<ll, ll> mp;
    ll m = 0;
    ll col;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        c++;
        if (i > 0)
        {
            if (arr[i] != arr[i - 1])
            {
                v.push_back(c);
                vc.push_back(arr[i - 1]);
                c = 0;
                mp[arr[i - 1]]++;
                // m = max(mp[arr[i - 1]], m);
                if (mp[arr[i - 1]] > m)
                {
                    col = mp[arr[i - 1]];
                    m = mp[arr[i - 1]];
                }
            }
        }
    }
    v.push_back(c);
    vc.push_back(arr[n - 1]);
    c = 0;
    mp[arr[n - 1]]++;
    if (mp[arr[n - 1]] > m)
    {
        col = mp[arr[n - 1]];
        m = mp[arr[n - 1]];
    }
    // m = max(mp[arr[n-1]], m);
    // cout<<vc.size()-m;
    // while(1)
    // {
    //     for(auto i:mp)
    //     {

    //     }
    // }
    // for(ll i=0;i<n;i++)
    {
        mp.clear();
        ll col, mcol = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                c = 0;
                mp[arr[i - 1]]++;
                if (mp[arr[i - 1]] > m)
                {
                    col = mp[arr[i - 1]];
                    m = mp[arr[i - 1]];
                }
            }
        }
        c = 0;
        mp[arr[n - 1]]++;
        if (mp[arr[n - 1]] > m)
        {
            col = mp[arr[n - 1]];
            m = mp[arr[n - 1]];
        }
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] == col)
            {
                count++;
            }
        }
    }

    // for (ll j = 0; j < vc.size(); j++)
    // {

    //     for (ll i = 0; i < vc.size(); i++)
    //     {
    //         if (v[i])
    //     }
    // }
}