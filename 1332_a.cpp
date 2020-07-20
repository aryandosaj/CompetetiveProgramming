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
ll a, b, c, d, x, y, x1, x2, y1, y2;
bool chk(ll xx, ll yy)
{
    return (x1 <= xx && xx <= x2 && yy >= y1 && yy <= y2);
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
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        ll xx = x + (b - a);
        ll yy = y + (d - c);
        ll f1 = 0, f2 = 0;
        if (chk(xx, yy))
        {
            if (b == a && a > 0)
                if (chk(x + 1, y) == 0 && chk(x - 1, y) == 0)
                    f1 = 1;

            if (d == c && c > 0)
                if (chk(x, y + 1) == 0 && chk(x, y - 1) == 0)
                    f2 = 1;
            if (f1 || f2)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
}