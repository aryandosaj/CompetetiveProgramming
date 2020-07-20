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
ll calc(ll n)
{
    string s = "";
    while (n > 9)
    {
        s.push_back('9');
        n -= 9;
    }
    if (n>0)
        s.push_back('0' + n);
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (auto i : s)
        ans = ans * 10 + (i - '0');
    return ans;
}
ll calc1(ll n)
{
    string s = "";
    if (n > 8)
        s.push_back('8'),
        n -= 8;
    while (n > 9)
    {
        s.push_back('9');
        n -= 9;
    }
    if (n>0)
        s.push_back('0' + n);
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (auto i : s)
        ans = ans * 10 + (i - '0');
    return ans;
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
        ll n, k;
        cin >> n >> k;
        ll ans = 1e18;
        f(0, 10)
        {
            if (i + k <= 9)
            {
                int sum = 0;
                fi(i, i + k + 1) sum += j;
                ll rem = n - sum;
                if (rem > 0)
                {
                    if (rem % (k + 1) == 0)
                    {
                        ll temp = calc(rem / (k + 1)) * 10 + i;
                        if (temp > 0)
                            ans = min(ans, temp);
                    }
                }
                else if (rem == 0)
                {
                    ans = min(ans, i);
                }
            }
            else
            {
                int sum = 0;
                fi(i, i + k + 1) sum += j % 10 + j / 10;
                ll rem = n - sum;
                if (rem > 0)
                {
                    if (rem % (k + 1) == 0)
                    {
                        ll temp = calc1(rem / (k + 1)) * 10 + i;
                        // cout<<i<<" "<<temp<<"\n";
                        if (temp > 0)
                            ans = min(ans, temp);
                    }
                }
                else if (rem == 0)
                {
                    ans = min(ans, i);
                }
            }
        }
        if (ans != 1e18)
            cout << ans << "\n";
        else
            cout << "-1\n";
    }
}