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
#define deb(x) cout << #x << "  " << x << endl;

//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}
ll dp[101][22][51][2];
ll v[51];
ll c[51];
ll n;
ll men[51];
ll rec(ll m, ll k, ll l, ll x)
{
    ll d = 0;
    if (k == 0 && m >= 0)
        return 0;
    if (m < 0)
        return -MOD;
    if (dp[m][k][l][x] != -1)
        return dp[m][k][l][x];
    ll val = -MOD;
    if (l == 0)
        f(1, n + 1)
            val = max(val, v[i] + rec(m - c[i], k - 1, i, 1));
    else
    {
        if (x == 1)
            val = max(val, v[l] / 2 + rec(m - c[l], k - 1, l, x + 1));
        if (x == 2)
            val = max(val, rec(m - c[l], k - 1, l, x));
        f(1, n + 1) if (i != l)
            val = max(val, v[i] + rec(m - c[i], k - 1, i, 1));
    }
    return dp[m][k][l][x] = val;
}
ll rec1(ll m, ll k, ll l, ll x)
{
    ll d = 0;
    if (k == 0 && m >= 0)
        return 0;
    if (m < 0)
        return -MOD;
    ll val = -MOD;
    if (l == 0)
    {
        f(1, n + 1)
        {
            ll temp = v[i] + rec(m - c[i], k - 1, i, 1);
            if (val < temp && temp >= 0)
            {
                val = temp;
                d = i;
            }
        }
    }
    else
    {
        if (x == 1)
        {
            ll temp = v[l] / 2 + rec(m - c[l], k - 1, l, x + 1);
            if (val < temp && temp >= 0)
            {
                val = temp;
                d = l;
            }
        }
        if (x == 2)
        {
            ll temp = rec(m - c[l], k - 1, l, 2);
            if (val < temp && temp >= 0)
            {
                val = temp;
                d = l;
            }
        }
        f(1, n + 1)
        {
            if (i != l)
            {
                ll temp = v[i] + rec(m - c[i], k - 1, i, 1);
                if (val < temp && temp >= 0)
                {
                    val = temp;
                    d = i;
                }
            }
        }
    }
    men[k] = d;
    if (l == d)
        rec1(m - c[d], k - 1, d, 2);
    else
        rec1(m - c[d], k - 1, d, 1);
    return val;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k, m;
    cin >> k >> n >> m;
    while (k)
    {
        memset(dp, -1, sizeof(dp));
        f(1, n + 1)
                cin >>
            c[i] >> v[i],
            v[i] *= 2;
        double val = rec(m, k, 0, 0) / 2.0;
        if (val > 0)
        {
            rec1(m, k, 0, 0);
            cout << fixed << setprecision(1) << val << "\n";
            f(1, k + 1) cout << men[k + 1 - i] << " ";
            cout << "\n";
        }
        else
        {
            cout << "0.0\n";
        }

        cin >> k >> n >> m;
    }
}