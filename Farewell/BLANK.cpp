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
ll arr[33];
unordered_map<ll, ll> mp1e;
unordered_map<ll, ll> mp1o;
unordered_map<ll, ll> mp2;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    f(0, n)
            cin >>
        arr[i];
    ll num = n / 2;

    f(1, (1 << num))
    {
        ll x = 0;
        ll c = 0;
        fi(0, num)
        {
            if ((1 << j) & i)
            {
                c++;
                if (c & 1)
                    x += arr[j];
                else
                    x = x - arr[j];
            }
        }
        if (c & 1)
            mp1o[x]++;
        else
            mp1e[x]++;
    }
    // for (auto i : mp1e)
    //     cout << i << "\n";

    ll num2 = n - num;
    f(1, (1 << num2))
    {
        ll x = 0;
        ll c = 0;
        fi(0, num2)
        {
            if ((1 << j) & i)
            {
                c++;
                if (c & 1)
                    x += arr[num + j];
                else
                    x = x - arr[num + j];
            }
        }
        mp2[x]++;
    }
    // for (auto i : mp2)
    //     cout << i << "\n";

    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        ll ans = 0;
        if (mp2.find(x) != mp2.end())
            ans += mp2[x];
        for (auto i : mp1e)
        {
            ll y = x - i.first;
            // cout<<i<<y<<"\n";
            if (y == 0)
                ans = ans + i.second * mp2[0] + i.second;
            else
            {
                if (mp2.find(y) != mp2.end())
                    ans += mp2[y] * i.second;
            }
        }

        for (auto i : mp1o)
        {
            ll y = i.first - x;
            if (y == 0)
                ans = ans + i.second * mp2[0] + i.second;
            else
            {
                if (mp2.find(y) != mp2.end())
                    ans += mp2[y] * i.second;
            }
        }
        cout << ans << "\n";
    }
}