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
ll lev[1000006];
ll lc[1000006];
ll rc[1000006];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vll v;
    set<ll> s;

    for (int i = 0; i < n; i++)
    {

        ll x;

        cin >> x;
        v.push_back(x);
        if (i == 0)
        {
            s.insert(x);
        }
        else
        {
            auto p = s.lower_bound(x);

            if (p == s.end() || lc[*p] == 1)
            {
                // cout<<"here";
                p--;
                // cout<<*p<<"\n";
                rc[*(p)] = 1;
                lev[x] = lev[*(p)] + 1;
            }
            else
            {
                lc[*(p)] = 1;
                lev[x] = lev[*(p)] + 1;
            }
            s.insert(x);
        }
    }
    for (auto i : v)
        cout << lev[i] + 1 << " ";
}