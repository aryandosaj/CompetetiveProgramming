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
struct dt
{
    char c;
    ll b;
    ll i;
    ll j;
};
dt dp[201][201][205];
ll vis[201][201][205];
string s1, s2;
ll l1, l2;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
    s1 = s1 + "_";
    s2 = s2 + "_";
    dp[0][0][0] = {' ', 0, 0, 0};
    queue<pair<ll, pl>> q;
    q.push({0, {0, 0}});
    while (!q.empty())
    {
        pair<ll, pl> u = q.front();
        q.pop();
        ll i = u.second.first;
        ll j = u.second.second;
        ll b = u.first;
        if (vis[b][i][j])
            continue;
        vis[b][i][j] = 1;
        if (i == l1 && j == l2 && b == 0)
        {
            string str = "";
            while (dp[b][i][j].c != ' ')
            {
                str.push_back(dp[b][i][j].c);
                ll b1 = dp[b][i][j].b;
                ll i1 = dp[b][i][j].i;
                ll j1 = dp[b][i][j].j;
                b = b1, i = i1, j = j1;
            }
            reverse(str.begin(), str.end());
            cout << str;
            return 0;
        }
        ll f = i, s = j;
        if (b < 200)
        {
            if (s1[f] == '(')
                f++;
            if (s2[s] == '(')
                s++;
            if (vis[b + 1][f][s] == 0)
            {
                dp[b + 1][f][s].c = '(';
                dp[b + 1][f][s].b = b;
                dp[b + 1][f][s].i = i;
                dp[b + 1][f][s].j = j;
                q.push({b + 1, {f, s}});
            }
        }
        if (b > 0)
        {
            f = i, s = j;
            if (s1[f] == ')')
                f++;
            if (s2[s] == ')')
                s++;
            if (vis[b - 1][f][s] == 0)
            {

                dp[b - 1][f][s].c = ')';
                dp[b - 1][f][s].b = b;
                dp[b - 1][f][s].i = i;
                dp[b - 1][f][s].j = j;
                q.push({b - 1, {f, s}});
            }
        }
    }

    return 0;
}