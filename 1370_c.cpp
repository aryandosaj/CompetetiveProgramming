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
        ll n, num;
        cin >> n;
        num = n;
        if (n & 1)
        {
            if (n != 1)
                cout << "Ashishgup\n";
            else
                cout << "FastestFinger\n";
        }
        else
        {
            if (n == 2)
            {
                cout << "Ashishgup\n";
                continue;
            }
            while ((n & 1) == 0)
                n /= 2;
            if (n == 1)
                cout << "FastestFinger\n";
            else
            {
                if (num / n == 2)
                {
                    ll f = 0;
                    for (int i = 3; i * i <= n; i += 2)
                        if (n % i == 0)
                        {
                            f = 1;
                            break;
                        }
                    if (f == 0)
                        cout << "FastestFinger\n";
                    else
                        cout << "Ashishgup\n";
                }
                else
                    cout << "Ashishgup\n";
            }
        }
    }
}