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
        string s1, s2;
        cin >> s1 >> s2;
        ll l1 = s1.length();
        ll l2 = s2.length();
        ll e = 0;
        for (int i = 0; i < min(l1, l2); i++)
        {
            if (s1[i] != s2[i])
                e = 1;
        }
        if (e == 0 && s1.length() < s2.length())
        {
            cout << s1 << "\n";
            continue;
        }
        vector<pair<char, ll>> v;
        set<pair<char, ll>> s;

        for (int i = l1 - 1; i >= 0; i--)
        {
            s.insert({s1[i], i});
            v.push_back(*s.begin());
        }
        reverse(v.begin(), v.end());
        char cc='-';ll ind=-1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first < s1[i])
            {
                cc=v[i].first;
                ind = i;
                break;
            }
        }
        for(int i=l1;i>=0;i--)
        {
            if(s1[i]==cc){
                swap(s1[i],s1[ind]);
                break;
            }
        }
        if (s1.compare(s2) < 0)
        {
            cout << s1 << "\n";
        }
        else
            cout << "---\n";
    }
    return 0;
}