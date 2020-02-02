#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
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
        ll x;
        string s;
        cin >> x >> s;
        ll ans = s.length();
        ll c = 0;
        while (c < x)
        {

            if (s[c] == '2')
            {
                string temp;
                if (s.length() <= x)
                {
                    for(int i=c+1;i<ans;i++)s.pb(s[i]);
                    // temp = s.substr(c + 1, s.length());
                    // s = s + temp;
                }
                ll len = (ans - c - 1 + mod) % mod;
                ans = (ans + len) % mod;
            }
            else if (s[c] == '3')
            {
                string temp;
                if (s.length() <= x)
                {
                    // temp = s.substr(c + 1, s.length());
                    // s = s + temp + temp;
                    for(int i=c+1;i<ans;i++)s.pb(s[i]);
                    for(int i=c+1;i<ans;i++)s.pb(s[i]);
                }
                ll len = (ans - c - 1 + mod) % mod;
                ans = (ans + ((len * 2) % mod)) % mod;
            }
            c++;
            ans = ans % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}