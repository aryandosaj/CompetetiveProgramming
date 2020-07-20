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
        string s[9];
        f(0, 9) cin >> s[i];
        s[0][0] = 10 - s[0][0] + '0'+'0';
        s[1][3] = 10 - s[0][3] + '0'+'0';
        s[2][6] = 10 - s[0][6] + '0'+'0';
        s[3][1] = 10 - s[3][1] + '0'+'0';
        s[4][4] = 10 - s[3][4] + '0'+'0';
        s[5][7] = 10 - s[3][7] + '0'+'0';
        s[6][2] = 10 - s[6][2] + '0'+'0';
        s[7][5] = 10 - s[6][5] + '0'+'0';
        s[8][8] = 10 - s[6][8] + '0'+'0';
        f(0, 9) cout << s[i] << "\n";
    }
}