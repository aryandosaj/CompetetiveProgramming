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
bool check(string s, string a)
{
    ll c = 0;
    f(0, s.length() - a.length() + 1)
    {
        ll f = 0;
        fi(0, a.length())
        {
            if (s[i + j] == a[j])
                continue;
            f = 1;
            break;
        }
        if (f == 0)
            c++;
    }
    if (c == 1)
        return 1;
    return 0;
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
    string a = "abacaba";
    while (t--)
    {
        ll n;
        string s;
        cin >> n >> s;
        ll c = 0;
        f(0, n - a.length() + 1)
        {
            ll f = 0;
            fi(0, a.length())
            {
                if (s[i + j] == a[j])
                    continue;
                f = 1;
                break;
            }
            if (f == 0)
                c++;
        }
        if (c > 1)
        {
            cout << "NO\n";
        }
        else if (c == 1)
        {
            cout << "YES\n";
            for (auto i : s)
            {
                if (i == '?')
                    cout << 'z';
                else
                    cout << i;
            }
            cout << "\n";
        }
        else
        {

            f(0, n - a.length() + 1)
            {
                ll f = 0;
                string temp = s;

                fi(0, a.length())
                {
                    if (s[i + j] == a[j] || s[i + j] == '?')
                        continue;
                    f = 1;
                    break;
                }
                if (f == 0)
                {

                    fi(0, a.length())
                    {
                        if (temp[i + j] == '?')
                            temp[i + j] = a[j];
                    }
                    if (check(temp, a))
                    {
                        s = temp;
                        break;
                    }
                }
            }
            if (check(s, a))
                cout << "YES\n";
            else
            {
                cout << "NO\n";
                continue;
            }
            for (auto i : s)
            {
                if (i == '?')
                    cout << 'z';
                else
                    cout << i;
            }
            cout << "\n";
        }
    }
}