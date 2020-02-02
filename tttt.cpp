#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define x first
#define y second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ve vector
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define sz(a) (int)(a.size())
//using namespace __gnu_pbds;
using namespace std;

// // // functions: find_by_order  & order_of_key
// typedef tree<
// int,
// null_type,
// less<int>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int inf = (int)2e9;
const long long mod = 1000000007; //1E9+7
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

ll powmod(ll a, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
            ans *= a;
        p /= 2;
        a *= a;
        ans %= mod;
        a %= mod;
    }
    return ans;
}
ll mdinv(ll a) { return powmod(a, mod - 2); }

inline int eval(ii a, int x)
{
    return a.x * x + a.y;
}
deque<ii> dq;
bool del(ii a)
{
    if (dq.size() <= 1)
        return 0;
    int n = dq.size();
    ii b1 = dq[n - 2], b2 = dq[n - 1];
    return (a.y - b1.y) * (b2.x - a.x) > (b1.x - a.x) * (a.y - b2.y);
}

signed main()
{
    IOS
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, c;
    cin >> n >> c;
    int x;
    cin >> x;
    dq.pb({-2 * x, x * x});
    vi DP(n);
    DP[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        while (dq.size() > 1 && eval(dq[0], x) > eval(dq[1], x))
            dq.pop_front();
        DP[i] = eval(dq[0], x) + x * x + c;
        ii here = {-2 * x, x * x + DP[i]};
        while (del(here))
            dq.pop_back();
        dq.push_back(here);
        // for(auto p:dq) cout<<"("<<p.x<<","<<p.y<<") ";
        // cout<<"\n";
        // cout<<"dp "<<DP[i]<<"\n";
    }
    cout << DP.back();
}