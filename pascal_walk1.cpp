#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
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
    fii(1, t + 1)
    {
        ll n;
        cin >> n;
        cout << "Case #" << k << ": "
             << "\n";
        if (n <= 50)
        {
            f(1, n + 1) cout << i << " " << 1 << "\n";
            continue;
        }
        n -= 50;
        ll req = 50;
        ll flag = 0;
        for (ll i = 0; req>0; i++)
        {
            if (i < 30 && ((n >> i) & 1))
            {

                if (flag == 0)
                    fi(1, i + 2)
                            cout
                        << i + 1 << " " << j << "\n";
                else
                    fi(1, i + 2)
                            cout
                        << i + 1 << " " << i + 1 + 1 - j << "\n";
                flag = flag ^ 1;
            }
            else
            {
                req--;
                if (flag == 0)
                    cout << i + 1 << " 1\n";
                else
                    cout << i + 1 << " " << i + 1 << "\n";
            }
        }
    }
}