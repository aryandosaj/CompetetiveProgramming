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
ll typ[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    pll a, b, ab;
    pll v;
    f(0, n)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        typ[i + 1] = x + y * 10;
        if (x && y)
            ab.pb({t, i + 1}), v.pb({t, i + 1});
        else if (x)
            a.pb({t, i + 1}), v.pb({t, i + 1});
        else if (y)
            b.pb({t, i + 1}), v.pb({t, i + 1});
        else
            v.pb({t, i + 1});
    }
    ll t = 0;
    vll ans;
    sort(ab.begin(), ab.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(v.begin(), v.end());
    if (ab.size() + a.size() < k || ab.size() + b.size() < k || v.size() < m)
    {
        cout << "-1";
        return 0;
    }
    if (2 * k >= m)
    {
        ll rem = 2 * k - m;
        ll ri = k - rem;
        if (rem > ab.size() || ri > a.size() || ri > b.size())
        {
            cout << "-1";   
            return 0;
        }
        for (auto i : ab)
            if (rem--)
                ans.pb(i.second), t += i.first;
        f(0, ri) ans.pb(a[i].second), t += a[i].first;
        f(0, ri) ans.pb(b[i].second), t += b[i].first;
    }
    else
    {
        ll ind = 0;
        pll p;
        ll aa = 0, bb = 0;
        f(0, m)
        {
            if (typ[v[ind].second] == 1)
                aa++;
            else if (typ[v[ind].second] == 10)
                bb++;
            else if (typ[v[ind].second] == 11)
                bb++, aa++;
            p.pb(v[ind++]);
        }
        if (aa >= k && bb >= k)
        {
            for (auto i : p)
            {
                ans.pb(i.second);
                t += i.first;
            }
        }
        else
        {
            if (aa < k)
            {
                ll ulta = ind - 1;
                ll seeda = ind;
                while (aa < k)
                {
                    while (ulta > 0)
                    {
                        if (typ[v[ulta].second] == 10 || typ[v[ulta].second] == 0)
                            break;
                        ulta--;
                    }
                    while (seeda < n)
                    {
                        if (typ[v[seeda].second] == 1 || typ[v[seeda].second] == 11)
                            break;
                        seeda++;
                    }
                    swap(v[ulta], v[seeda]);
                    if (typ[v[seeda].second] == 1)
                        aa++;
                    else
                        bb++, aa++;
                    ulta--;
                    seeda++;
                }
                f(0, m)
                {
                    ans.pb(v[i].second);
                    t += v[i].first;
                }
            }
            else
            {
                ll ulta = ind - 1;
                ll seeda = ind;
                while (bb < k)
                {
                    while (ulta > 0)
                    {
                        if (typ[v[ulta].second] == 1 || typ[v[ulta].second] == 0)
                            break;
                        ulta--;
                    }
                    while (seeda < n)
                    {
                        if (typ[v[seeda].second] == 10 || typ[v[seeda].second] == 11)
                            break;
                        seeda++;
                    }

                    swap(v[ulta], v[seeda]);
                    if (typ[v[seeda].second] == 10)
                        bb++;
                    else
                        bb++, aa++;
                    ulta--;
                    seeda++;
                }
                f(0, m)
                {
                    ans.pb(v[i].second);
                    t += v[i].first;
                }
            }
        }
    }
    cout << t << "\n";
    for (auto i : ans)
        cout << i << " ";
}