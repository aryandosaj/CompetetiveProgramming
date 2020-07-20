#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
ll l[100005];
ll post[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll f = 0;
    vll v;
    ll mm = 0;
    ll s = 0;
    f(1, m + 1)
    {
        cin >> l[i];
        if (l[i] > (n - i + 1))
            f = 1;
        v.pb(i);
        mm = max(mm, i - 1 + l[i]);
        s += l[i];
    }
    ll p = 0;
    for (ll i = m; i > 0; i--)
    {
        post[i] = p;
        p = max(p, i + l[i]-1);
        
    }
    // cout<<n-mm<<"\n";
    if (f || s < n)
        cout << "-1";
    else
    {
        if (mm == n)
        {
            for (auto i : v)
                cout << i << " ";
        }
        else
        {
            v.clear();
            ll c = 0;
            f(1, m + 1)
            {
                v.pb(i + c);
                ll rc = (m - i);
                // cout << i << " " << c << " " << post[i] << "\n";
                if (post[i] + c < n)
                {
                    ll rem = n - post[i] - c;
                    ll x = min(l[i] - 1, rem);
                    c += x;
                }
            }
            for (auto i : v)
                cout << i << " ";
        }
    }
}