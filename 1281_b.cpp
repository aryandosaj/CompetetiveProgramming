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
        string s, c;
        cin >> s >> c;
        ll l = c.length();
        ll f = 1;
        ll e = 0;
        ll ind = 0;
        f(0, s.length())
        {
            if (s[i] != c[i])
                e = 1;
            if (i >= l)
            {
                break;
            }
            if (s[i] > c[i])
            {
                f = 1;
                break;
            }
            if (s[i] < c[i])
            {
                f = 0;
                break;
            }
        }
        // cout<<e<<" "<<f<<" "<<s.length()<<" "<<c.length()<<"\n";
        if (f == 0)
        {
            cout << s << "\n";
        }
        else if (e == 0 && s.length() < c.length())
        {
            cout << s << "\n";
        }
        else
        {
            vector<set<char>> v;
            set<char> ss;
            for (ll i = s.length() - 1; i >= 0; i--)
            {

                v.push_back(ss);
                ss.insert(s[i]);
            }
            reverse(v.begin(), v.end());
            f = 0;

            for (int i = 0; i < l; i++)
            {
                if (i < s.length() - 1)
                {

                    if (s[i] == c[i])
                    {
                        char cc = *v[i].begin();
                        // cout << s[i] << " " << c[i] <<" "<<cc<<"\n";
                        if (cc < c[i])
                        {
                            f = 1;
                            ind = i;
                            break;
                        }
                        else
                            continue;
                    }
                    else
                    {
                        // cout << s[i] << " " << c[i] << "\n";

                        char cc = *v[i].begin();
                        if (cc <= c[i])
                        {
                            f = 1;
                            ind = i;
                            break;
                        }
                        else if (s[i] > c[i])
                            break;
                    }
                }
                else
                    break;
            }
            if (f)
            {
                ll k = 0;
                for (int i = s.length() - 1; i > ind; i--)
                {
                    if (s[i] < c[ind])
                    {
                        k = 1;
                        swap(s[i], s[ind]);
                        break;
                    }
                }
                if (k == 0)
                {
                    for (int i = s.length() - 1; i > ind; i--)
                    {
                        if (s[i] < c[ind])
                        {
                            k = 1;
                            swap(s[i], s[ind]);
                            break;
                        }
                    }
                }
                f = 0, e = 0;
                f(0, s.length())
                {
                    if (s[i] != c[i])
                        e = 1;
                    if (i >= l)
                        break;
                    if (s[i] < c[i])
                    {
                        f = 1;
                        break;
                    }
                    else if (s[i] > c[i])
                    {
                        f = 0;
                        break;
                    }
                }
                if (e == 0 && s.length() < c.length())
                    cout << s << "\n";
                else
                {

                    if (f)
                        cout << s << "\n";
                    else
                        cout << "---\n";
                }
            }
            else
                cout << "---\n";
        }
    }
    return 0;
}