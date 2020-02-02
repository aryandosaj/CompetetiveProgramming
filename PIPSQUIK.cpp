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
        ll n, h, y1, y2, l, c = 0;
        cin >> n >> h >> y1 >> y2 >> l;
        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++)
        {
            ll ti, x;
            cin >> ti >> x;
            v.push_back({ti, x});
        }
        for (auto i : v)
        {
            if (i.first == 1)
            {
                if ((h - y1) <= i.second)
                    c++;
                else
                    l--, c++;
            }
            else
            {
                if (y2 >= i.second)
                    c++;
                else
                    l--, c++;
            }
            if (l <= 0)
                break;
        }
        if (l == 0)
            cout << c - 1 << "\n";
        else
            cout << c << "\n";
    }
}