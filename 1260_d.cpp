#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
inline ll power(ll a, ll b, ll mod)
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
#define deb(x) cout << #x << x << endl;
ll a[200005];
vector<pair<ll, pair<ll, ll>>> v;
vll lef[200005];
vll righ[200005];
ll vis[200005];
ll markl[200005];
ll markr[200005];
ll done[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m, n, k, t;
    cin >> m >> n >> k >> t;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
    {
        ll l, r, d;
        cin >> l >> r >> d;
        v.push_back({d, {l, r}});
    }
    sort(a, a + m);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        ll l = v[i].second.first;
        ll r = v[i].second.second;
        lef[l].push_back(i);
        righ[r].push_back(i);
    }
    t = t - (n + 1);
    if (t < 0)
    {
        cout << "0";
        return 0;
    }
    ll danger = v[0].first;
    for (int i = 0; i < v.size(); i++)
    {
        // deb(t);
        ll l = v[i].second.first;
        ll r = v[i].second.second;
        if (done[i])
        {
            danger = (i == (v.size() - 1)) ? 0 : v[i + 1].first;
            continue;
        }
        if (r >= l)
        {
            if ((markl[i] & markr[i]) == 1)
                t = t - (r - l - 1) * 2;
            else if ((markl[i] || markr[i]) == 0)
                t = t - (r - l + 1) * 2;
            else
                t = t - (r - l) * 2;
        }

        if (t < 0)
            break;
        danger = (i == v.size() - 1) ? 0 : v[i + 1].first;
        for (int j = l; j <= r; j++)
        {
            vis[j] = 1;
            vll temp;
            set<ll> s;
            {
                for (auto k : lef[j])
                {
                    v[k].second.first = r, temp.push_back(k), markl[k] = 1, s.insert(k);
                }
                for (auto k : temp)
                    lef[r].push_back(k);
                temp.clear();
            }
            {
                for (auto k : righ[j])
                {
                    v[k].second.second = l, temp.push_back(k), markr[k] = 1;
                    if (s.find(k) != s.end())
                        done[k] = 1;
                }
                for (auto k : temp)
                    righ[l].push_back(k);
                temp.clear();
            }
        }
    }
    // deb(danger);
    ll ans = m - (lower_bound(a, a + m, danger) - a);
    cout << ans;
}