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
ll arr[200005];
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
        ll n;
        cin >> n;
        ll c = 0;
        f(1, n + 1)
        {
            cin >> arr[i];
            if (arr[i] == i)
                c++;
        }
        if (c == n)
        {
            cout << "0\n";
        }
        else if (c == 0)
        {
            cout << "1\n";
        }
        else
        {
            ll f = 0;
            ll num = 0;
            f(1, n + 1)
            {
                if (f == 0)
                {

                    if (arr[i] != i)
                    {
                        f = 1;
                        num++;
                    }
                }
                else
                {
                    if (arr[i] == i)
                    {
                        f = 0;
                    }
                }
            }
            if (num > 1)
                cout << "2\n";
            else
                cout << "1\n";
        }
    }
}