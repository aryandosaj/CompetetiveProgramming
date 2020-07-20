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
void prn(vll &v, ll n)
{

    ll arr[n][n];
    ll i = 0, ii = 0, jj = 0, f = 0;
    while (i < v.size())
    {
        arr[ii][jj] = v[i++];
        ii++;
        jj++;
        if (ii == n)
            jj = ++f;
        ii = ii % n;
        jj = jj % n;
    }
    f(0, n)
    {
        fi(0, n)
                cout
            << arr[i][j] << " ";
        cout << "\n";
    }
}

void prn1(vll &v, ll n)
{

    ll arr[n][n];
    ll i = 0, ii = 0, jj = 0, f = 0;
    while (i < v.size())
    {
        arr[n - 1 - ii][jj] = v[i++];
        ii++;
        jj++;
        if (ii == n)
            jj = ++f;
        ii = ii % n;
        jj = jj % n;
    }
    f(0, n)
    {
        fi(0, n)
                cout
            << arr[i][j] << " ";
        cout << "\n";
    }
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
    ll c = 0;
    while (t--)
    {
        c++;
        ll n, k;
        cin >> n >> k;
        vll v;

        if ((k / n) <= n && k % n == 0)
        {
            ll d = k / n;
            f(1, n + 1) fi(1, n + 1) v.pb(((i + d - 1) <= n) ? (i + d - 1) : ((i + d - 1) - n));
            cout << "Case #" << c << ": POSSIBLE\n";
            prn(v, n);
        }
        else if (n == 5 && k == 15)
        {
            ll d = 1;
            f(1, n + 1) fi(1, n + 1) v.pb(((i + d - 1) <= n) ? (i + d - 1) : ((i + d - 1) - n));
            cout << "Case #" << c << ": POSSIBLE\n";
            prn1(v, n);
        }
        else //Impossible
            cout << "Case #" << c << ": IMPOSSIBLE\n";
    }
}