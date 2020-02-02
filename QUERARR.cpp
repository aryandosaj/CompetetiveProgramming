#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        map<ll, vector<ll>> mp;
        map<ll,ll>visit;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            visit[arr[i]]=1;
            mp[arr[i]].push_back(i);
        }
        ll q;
        cin >> q;

        while (q--)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            if (visit[x]==0)
            {

                cout << "no\n";

                continue;
            }
            ll p = lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin();
            // cout<<p<<" --";
            if (p == mp[x].size())
            {

                cout << "no\n";

                continue;
            }
            ll val = mp[x][p];
            if (val > r)
            {

                cout << "no\n";
            }
            else
            {

                cout << "yes\n";
            }
        }
    }
}