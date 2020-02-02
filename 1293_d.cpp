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
ll arr[100][2];
ll pre[100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    arr[0][0] = x0;
    arr[0][1] = y0;
    ll c = 1;
    f(1, 100)
    {
        if (arr[i-1][0] > (2e18/ax) || arr[i-1][1] > (2e18)/ay)
            break;
        ll x1 = arr[i - 1][0] * ax + bx;
        ll y1 = arr[i - 1][1] * ay + by;
        c++;
        arr[i][0] = x1;
        arr[i][1] = y1;
        pre[i] = x1 - arr[i - 1][0] + y1 - arr[i - 1][1];
        // cout<<x1<<" "<<y1<<"\n";
   
    }
    ll ans = 0;
    f(0, c)
    {
        ll a = 0;
        ll temp = abs(xs - arr[i][0]) + abs(ys - arr[i][1]);
        ll temp1 = 0;
        ll tim = t;
        tim -= temp;
        if (tim < 0)
            continue;
        a++;
        ans = max(a, ans);
        for (int j = i; j > 0; j--)
        {

            temp1 += pre[j];
            tim -= pre[j];
            if (tim < 0)
                break;
            a++;
            ans = max(a, ans);
        }
        tim -= temp1;
        if (tim < 0)
            continue;
        for (int j = i + 1; j < c; j++)
        {
            tim -= pre[j];
            if (tim < 0)
                break;
            a++;
        }
        ans = max(a, ans);
    }
    cout << ans;
}