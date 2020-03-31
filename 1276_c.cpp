#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
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
ll bit[400005];
ll bit1[400005];
ll arr[400005];
map<ll, ll> mp;
vector<pl> s;
void insert(ll ind)
{
    for (ll i = ind; i < 400005; i += i & -i)
        bit[i] += 1;
}
ll query(ll ind)
{
    ll ret = 0;
    for (ll i = ind; i > 0; i -= i & -i)
        ret += bit[i];
    return ret;
}
void insert1(ll ind)
{
    for (ll i = ind; i < 400005; i += i & -i)
        bit1[i] += ind;
}
ll query1(ll ind)
{
    ll ret = 0;
    for (ll i = ind; i > 0; i -= i & -i)
        ret += bit1[i];
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll x = 1;
    while (x * x <= n)
        x++;
    x--;
    f(0, n) cin >> arr[i], mp[arr[i]]++;
    ll p, q;
    ll ans = 0;
    ll lans = -1;
    for (auto i : mp)
        insert(i.second), insert1(i.second);
    ll num = mp.size();
    f(1, x + 1)
    {
        ll c = 0;
        ll c1 = (num-query(i))*i;
        ll c2 = query1(i);
        c=c1+c2;
        ll v = (c / i);
        ll temp = i * v;
        if (temp > ans && i <= v)
        {
            ans = temp;
            p = i;
            q = v;
        }
    }
    ll ii = 0, jj = 0;
    ll a[p][q];
    cout << ans << "\n"
         << p << " " << q << "\n";
    ll count = 0;
    ll f = 0;
    for (auto i : mp)
        s.pb({min(p, i.second), i.first});
    sort(s.begin(), s.end(), greater<pl>());
    for (auto i : s)
    {
        ll x = min(p, i.first);
        while (x--)
        {
            if (count == p * q)
                break;
            a[ii][jj] = i.second;
            ii++;
            jj++;
            if (ii == p)
                jj = ++f;
            ii = ii % p;
            jj = jj % q;
            count++;
        }
    }
    f(0, p)
    {
        fi(0, q) cout << a[i][j] << " ";
        cout << "\n";
    }
}