#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
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
class Compare
{
public:
    bool operator()(ll a, ll b)
    {
        return a>b; 
    }
};
unordered_map<ll, ll> mp;
set<ll> b;
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
        mp.clear();
        b.clear();
        ll n, p;
        cin >> n >> p;
        string s;
        cin >> s;
        ll c=0;
        for (auto i : s)
        {
            if (i == 'a')
                b.insert(c);
            c++;
        }
        f(0,n)
        {
            if (p)
            {
                if (s[i] == 'b')
                {
                    if (mp[i] == 1)
                    {
                        p--;
                        s[i] = 'a';
                        continue;
                    }
                    else if (b.size())
                    {
                        ll pp = *prev(b.end());
                        swap(s[i], s[pp]);
                        mp[pp] = 1;
                        b.erase(pp);
                        p--;

                    }
                    else if(p>1)
                    {
                        p-=2;
                        s[i]='a';
                    }
                }
                else
                {
                    b.erase(i);
                }
            }
            else
                break;
        }
        cout<<s<<"\n";
    }
}