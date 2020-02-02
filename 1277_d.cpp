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
        ll n, zz = 0, oo = 0, zo = 0, oz = 0;
        cin >> n;
        string ss[n];
        unordered_map<string, ll> mp;
        f(0, n)
        {
            string s;
            cin >> s;
            mp[s] = 1;
            ss[i] = s;
            if (s[0] == '0' && s[s.length() - 1] == '0')
                zz++;
            if (s[0] == '0' && s[s.length() - 1] == '1')
                zo++;
            if (s[0] == '1' && s[s.length() - 1] == '0')
                oz++;
            if (s[0] == '1' && s[s.length() - 1] == '1')
                oo++;
        }
        if (oz > 0 || zo > 0)
        {
            if (oz > zo)
            {
                ll x = (oz - zo) / 2;
                vll v;
                f(0, n)
                {
                    if (x == 0)
                        break;
                    if (ss[i][0] == '1' && ss[i][ss[i].length() - 1] == '0')
                    {
                        reverse(ss[i].begin(), ss[i].end());
                        if (mp[ss[i]] == 0)
                            x--, v.push_back(i + 1);
                    }
                }
                if (x == 0)
                {
                    cout << v.size() << "\n";
                    for (auto i : v)
                        cout << i << " ";
                    cout << "\n";
                }
                else
                    cout << "-1\n";
            }
            else
            {
                ll x = (zo - oz) / 2;
                vll v;
                f(0, n)
                {
                    if (x == 0)
                        break;
                    if (ss[i][0] == '0' && ss[i][ss[i].length() - 1] == '1')
                    {
                        reverse(ss[i].begin(), ss[i].end());
                        if (mp[ss[i]] == 0)
                            x--, v.push_back(i + 1);
                    }
                }
                if (x == 0)
                {
                    cout << v.size() << "\n";
                    for (auto i : v)
                        cout << i << " ";
                    cout << "\n";
                }
                else
                    cout << "-1\n";
            }
        }
        else
        {
            if (zz > 0 && oo > 0)
            {
                cout << "-1\n";
                continue;
            }
            else
            {
                cout << "0\n\n";
                continue;
            }
        }
    }
    return 0;
}