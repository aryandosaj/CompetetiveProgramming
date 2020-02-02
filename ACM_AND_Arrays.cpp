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
ll arr[100005];
ll dc[320][320];
ll mul[320][320];
ll val[320];
ll ml[320];
ll mull[320];
map<ll, set<ll>> mp[320];
void rem(ll st, ll val, ll ind)
{
    mp[st][val].erase(ind);
}
void add(ll st, ll val, ll ind)
{
    mp[st][val].insert(ind);
}
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
    f(0, n) cin >> arr[i];
    ll num = 320;
    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            ll st = l / num;
            ll en = r / num;
            if (st == en)
            {
                f(st * num, (st + 1) * num)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] = dc[st][i - st * num] * ml[st] + val[st],
                                    add(st, dc[st][i - st * num], i);
                mull[st] /= ml[st];
                val[st] = 0;
                ml[st] = 1;
                f(l, r + 1)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] += x,
                    add(st, dc[st][i - st * num], i);
            }
            else
            {
                f(st * num, (st + 1) * num)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] = dc[st][i - st * num] * ml[st] + val[st],
                                    add(st, dc[st][i - st * num], i);
                mull[st]/=ml[st];
                val[st] = 0;
                ml[st] = 1;
                f(l, (st + 1) * num)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] += x,
                    add(st, dc[st][i - st * num], i);

                f(en * num, min(n, (en + 1) * num))
                    rem(en, dc[en][i - en * num], i),
                    dc[en][i - en * num] = dc[en][i - en * num] * ml[en] + val[en],
                                    add(en, dc[en][i - en * num], i);
                mull[en]/=ml[en];
                val[en] = 0;
                ml[en] = 1;
                f(en * num, r + 1)
                    rem(en, dc[en][i - en * num], i),
                    dc[en][i - en * num] += x,
                    add(en, dc[en][i - en * num], i);

                f(st + 1, en)
                    val[i] = val[i] * ml[i] + x,
                    ml[i] = 1;
            }
        }
        else if (t == 2)
        {
            ll l, r, y;
            cin >> l >> r >> y;
            ll st = l / num;
            ll en = r / num;
            if (st == en)
            {
                f(st * num, (st + 1) * num)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] = dc[st][i - st * num] * ml[st] + val[st],
                                    add(st, dc[st][i - st * num], i);
                mull[st]/=ml[st];
                val[st] = 0;
                ml[st] = 1;
                mull[st]*=y;
                f(l, r + 1)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] *= y,
                    add(st, dc[st][i - st * num], i);
            }
            else
            {

                f(st * num, (st + 1) * num)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] = dc[st][i - st * num] * ml[st] + val[st],
                                    add(st, dc[st][i - st * num], i);
                mull[st]/=ml[st];
                val[st] = 0;
                ml[st] = 1;
                f(l, (st + 1) * num)
                    rem(st, dc[st][i - st * num], i),
                    dc[st][i - st * num] *= y, mul[st][i - st * num] *= y,
                    add(st, dc[st][i - st * num], i);

                f(en * num, min(n, (en + 1) * num))
                    rem(en, dc[en][i - en * num], i),
                    dc[en][i - en * num] = dc[en][i - en * num] * ml[en] + val[en],
                                    add(en, dc[en][i - en * num], i);
                mull[en]/=ml[en];
                val[en] = 0;
                ml[en] = 1;
                f(en * num, r + 1)
                    rem(en, dc[en][i - en * num], i),
                    dc[en][i - en * num] *= y, mul[st][i - st * num] *= y,
                    add(en, dc[en][i - en * num], i);

                f(st + 1, en)
                    ml[i] *= y,
                    mull[i] *= y;
            }
        }
        else
        {
            ll z;
            cin >> z;
            f(0,n/num+1)
            {
                
            }
        }
    }
}