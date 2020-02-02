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
set<ll> s;
pair<ll, ll> arr[100005];
// unordered_map<ll, ll> mp;
unordered_map<ll, ll> rmp;
map<ll, ll> mp;
map<ll, ll> p2;
ll pre[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        s.insert(arr[i].first);
        s.insert(arr[i].second);
        mp[arr[i].first]++;
        mp[arr[i].second + 1]--;
    }
    ll c = 0;
    cin >> x >> y;

    for (auto pp = mp.begin(); pp != mp.end(); pp++)
    {
        c += (*pp).second;
        p2[(*pp).first] = c;
    }
    // for (auto i : p2)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    if (mp.find(0) == mp.end())
        p2[0] = 0;
    c = 0;
    ll ans = 0;
    ll f = 0;
    for (auto pp = p2.begin(); pp != p2.end(); pp++)
    {
        ll num = (*pp).second;
        ll val = (*pp).first;
        if (f)
        {
            if (num >= x && num <= y)
            {
               continue; 
            }
            else{
                ans+=val-c;
                f=0;
            }            
        }
        else{
            if (num >= x && num <= y)
            {
               c=val;
               f=1; 
            }
        }

    }

    cout << ans;

    //////////////////////////////
    // int c = 1;
    // for (auto i : s)
    // {
    //     rmp[c] = i;
    //     mp[i] = c++;
    //     // c++;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     pre[arr[i].first]++;
    //     pre[arr[i].second + 1]--;
    // }
    // for (int i = 1; i < 100005; i++)
    //     pre[i] += pre[i - 1];
    // ll f = 0;
    // ll start = 0;
    // ll ans = 0;
    // for(int i=0;i<c;i++)cout<<pre[i]<<"\n";
    // for (int i = 1; i < c; i++)
    // {
    //     if (f)
    //     {
    //         if (pre[i] >= x && pre[i] <= y)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             // if (rmp[i - 1] == 0)
    //             //     continue;
    //             f = 0;
    //             ans += (rmp[i - 1] - rmp[start]);
    //         }
    //     }
    //     else
    //     {
    //         if (pre[i] >= x && pre[i] <= y)
    //         {
    //             f = 1;
    //             start = i;
    //         }
    //     }
    // }
    // cout << ans;
}