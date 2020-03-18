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
ll arr[100005][27];
ll sum[27];
ll mp[26][26];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (ll i = s.length() - 1; i >= 0; i--)
    {
        for (ll j = 0; j < 26; j++)
            sum[j] += (s[i] == (j + 'a'));
        for (ll j = 0; j < 26; j++)
            arr[i][j] = sum[j];
    }
    ll ans = 0;
    f(0, 26) ans = max(ans, sum[i]);
    f(0, 26) ans = max(ans, (sum[i] * (sum[i] - 1)) / 2), sum[i] = 0;
    f(0, s.length() - 1)
    {
        // for (ll j = 0; j < 26; j++)
        //     if (s[i] == (char)(j + 'a'))
        //         sum[j]++;
        fi(0, 26)
        {
            fii(0, 26)
            {
                if (j != k&&s[i]==(j+'a'))
                    mp[j][k] += arr[i][k],
                        ans = max(ans, mp[j][k]);
            }
        }
    }
    cout << ans << "\n";
}