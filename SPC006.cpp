#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
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
pair<ll, ll> arr[10004];
pll v;
ll dp[10004];
ll nex[10004];
ll lena[10004];
ll n;
bool chk(ll i)
{
    if (arr[i + 1].first & 1)
    {
        if (arr[i].first > (arr[i + 1].first / 2))
        {
            return 1;
        }
    }
    else
    {
        if (arr[i].first >= (arr[i + 1].first / 2))
        {
            return 1;
        }
    }
    return 0;
}

ll rec(ll ind)
{
    if (dp[ind] != -1)
        return dp[ind];
    if (ind >= n - 1)
        return 0;
    ll ans = rec(ind + 1);
    nex[ind] = ind + 1;
    lena[ind] = 0;
    if (chk(ind))
    {
        ll temp = rec(ind + 2) + 1;
        if (temp > ans)
        {
            nex[ind] = ind + 2;
            lena[ind] = 1;
            ans = temp;
        }
    }
    return dp[ind] = ans;
}
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
        memset(dp, -1, sizeof(dp));
        memset(lena, 0, sizeof(lena));
        memset(nex, 0, sizeof(nex));
        v.clear();
        cin >> n;
        f(0, n) cin >> arr[i].first, arr[i].second = i + 1;
        sort(arr, arr + n);
        ll siz = rec(0);
        ll ind = 0;
        if (siz == 0)
        {
            cout << "0\n";
            continue;
        }
        while (1)
        {
            
            if (lena[ind])
            {
                v.pb({arr[ind].second, arr[ind + 1].second});
            }
            ind = nex[ind];
            if (ind == 0)
                break;
        }
        cout << v.size() << "\n";
        for (auto i : v)
            cout << i.first << " " << i.second << "\n";
    }
    return 0;
}