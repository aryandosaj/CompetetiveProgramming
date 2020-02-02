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
ll dp[2][101][10000];
ll str_to_num(string s)
{
    ll num = 0;
    for (auto i : s)
    {
        num = num * 10 + (i - '0');
    }
    return num;
}
char next_char(char a)
{
    if (a == '9')
        return '0';
    else
        return a + 1;
}
ll rec(string s, ll m, ll f)
{
    ll ans;
    ll num = str_to_num(s);
    if (dp[f][m][num] != -1)
        return dp[f][m][num];
    if (m == 0)
        return str_to_num(s);
    if (f)
    {
        string temp = s;
        temp[0] = next_char(s[0]);
        ans = rec(temp, m - 1, 1 - f);
        temp[0] = s[0];
        temp[1] = next_char(s[1]);
        ans = max(ans, rec(temp, m - 1, 1 - f));
        temp[1] = s[1];
        temp[2] = next_char(s[2]);
        ans = max(ans, rec(temp, m - 1, 1 - f));
        temp[2] = s[2];
        temp[3] = next_char(s[3]);
        ans = max(ans, rec(temp, m - 1, 1 - f));
    }
    else
    {
        string temp = s;
        temp[0] = next_char(s[0]);
        ans = rec(temp, m - 1, 1 - f);
        temp[0] = s[0];
        temp[1] = next_char(s[1]);
        ans = min(ans, rec(temp, m - 1, 1 - f));
        temp[1] = s[1];
        temp[2] = next_char(s[2]);
        ans = min(ans, rec(temp, m - 1, 1 - f));
        temp[2] = s[2];
        temp[3] = next_char(s[3]);
        ans = min(ans, rec(temp, m - 1, 1 - f));
    }
    return dp[f][m][num] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    ll t;
    cin >> t;
    while (t--)
    {
       
        string num;
        ll m;
        cin >> num >> m;
        ll a = rec(num, m, 1);
        ll n = str_to_num(num);
        // deb(a);
        if (a > n)
            cout << "Berlin\n";
        else
            cout << "Professor\n";
    }
    return 0;
}