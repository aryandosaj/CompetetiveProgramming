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
ll aa[100005];
ll bb[100005];
vector<pair<pl, ll>> x;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {

        x.clear();
        ll n, m;
        cin >> n >> m;
        f(0, m) aa[i] = 0, bb[i] = 0;
        pll v;
        f(0, m)
        {
            ll a, b;
            cin >> a >> b;
            v.pb({a, b});
            x.pb({{a, 0}, i});
            x.pb({{b, 1}, i});
        }
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        ll ans = 0;
        ll a = 0;
        ll c = n;
        ll temp = 0;
        f(0, x.size())
        {
            if(c==0)break;
            // cout<<x[i].first.first<<" "<<x[i].first.second<<" "<<x[i].second<<" "<<c<<" "<<a<<" ";
            // cout<<ans<<"\n";
            if (x[i].first.second == 0 && aa[x[i].second] == 0)
            {
                ans += x[i].first.first;
                c--;
                aa[x[i].second] = 1;
            }
            else
            {
                if (aa[x[i].second] == 1)
                {
                    ans += (c * x[i].first.first);
                    c=0;
                }
                else if (aa[x[i].second] == 0)
                {
                    temp = ans + v[x[i].second].first + (c - 1) * v[x[i].second].second;
                    a = max(a,max(ans, temp));
                    aa[x[i].second] = 2;
                    bb[x[i].second] = 2;
                }
            }
        }
        cout << max(a, ans) << "\n";
    }
}