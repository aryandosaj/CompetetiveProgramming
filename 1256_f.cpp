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
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        string s, t;
        cin>>n;
        cin >> s >> t;
        map<char, ll> ss, tt, pos;
        ll c = 0;
        ll flag = 0, f = 0;
        for (auto i : s)
            ss[i]++;
        for (auto i : t)
            tt[i]++, pos[i] = c++;
        for (auto i : ss)
        {
            if (tt[i.first] != i.second)
            {
                flag = 1;
                break;
            }
            if (tt[i.first] > 1)
                f = 1;
        }
        if (flag)
        {
            cout << "NO\n";
            continue;
        }
        if (f)
        {
            cout << "YES\n";
            continue;
        }
        ll temp = 0;
        f(0, n)
        {
            ll k = 0;
            fi(0, n)
            {
                if(s[i] == t[j])
                {
                    k = j;
                    break;
                }
            }
            for (ll p = k; p > i; p--)
                swap(t[p], t[p - 1]), temp++;
            // cout<<s<<"\n"<<t<<"\n";
        }
        // deb(temp);
        if (temp & 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}