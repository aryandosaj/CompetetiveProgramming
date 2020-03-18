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
pl tree[400005];
string s;
void mer(ll posl, ll posr, ll pos)
{
    tree[pos].first = tree[posl].first;
    tree[pos].second = tree[posr].second;
    if (tree[posl].second >= tree[posr].first)
        tree[pos].second += tree[posl].second - tree[posr].first;
    else
        tree[pos].first += tree[posr].first - tree[posl].second;
}
void build(ll l, ll h, ll pos)
{
    if (l == h)
    {
        if (s[l] == '(')
            tree[pos].second = 1, tree[pos].first = 0;
        else
            tree[pos].second = 0, tree[pos].first = 1;
        return;
    }
    ll m = (l + h) / 2;
    build(l, m, 2 * pos + 1);
    build(m + 1, h, 2 * pos + 2);
    mer(2 * pos + 1, 2 * pos + 2, pos);
}
void update(ll l, ll h, ll pos, ll ind)
{
    if (l == h)
    {
        if (s[l] == '(')
        {
            s[l] = ')';
            tree[pos].second = 0, tree[pos].first = 1;
        }
        else
        {
            s[l] = '(';
            tree[pos].second = 1, tree[pos].first = 0;
        }
        return;
    }
    ll m = (l + h) / 2;
    if (ind <= m)
        update(l, m, 2 * pos + 1, ind);
    else
        update(m + 1, h, 2 * pos + 2, ind);
    mer(2 * pos + 1, 2 * pos + 2, pos);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 10;
    while (t--)
    {
        cout<<"Test "<<10-t<<":\n";
        f(0,400005)tree[i]={0,0};
        ll n;
        cin >> n;
        cin >> s;
        build(0,n-1,0);
        ll m;
        cin >> m;
        while (m--)
        {
            ll k;
            cin >> k;
            if (k)
                update(0, n - 1, 0, k-1);
            else
            {
                if (tree[0].first == 0 && tree[0].second == 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}