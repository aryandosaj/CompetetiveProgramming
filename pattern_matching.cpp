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
    fii (1,t+1)
    {
        ll n;
        cin >> n;
        string p[n];
        string ml;
        ll len = 0;
        string ml1;
        ll len1 = 0;
        vector<string> vl, vr;
        f(0, n)
        {

            cin >> p[i];
            string temp = "";
            fi(0, p[i].length())
            {
                if (p[i][j] == '*')
                    break;
                temp.pb(p[i][j]);
            }
            vl.pb(temp);
            if (temp.length() > len)
            {
                ml = temp;
                len = temp.length();
            }
            ll z = temp.length() + 1;
            temp = "";
            fi(z, p[i].length())
                temp.pb(p[i][j]);
            reverse(temp.begin(), temp.end());
            vr.pb(temp);
            if (temp.length() > len1)
            {
                ml1 = temp;
                len1 = temp.length();
            }
        }
        string ans = "";
        ll flag = 0;
        f(0, len)
        {
            char c = ml[i];
            for (auto j : vl)
            {
                if (j.length() > i)
                {
                    if (j[i] != c)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                break;
            ans.pb(c);
        }
        string ans2 = "";
        f(0, len1)
        {
            char c = ml1[i];
            for (auto j : vr)
            {
                if (j.length() > i)
                {
                    if (j[i] != c)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                break;
            ans2.pb(c);
        }
        reverse(ans2.begin(), ans2.end());
        ans = ans + ans2;
        cout<<"Case #"<<k<<": "; 
        if (flag == 0)
            cout << ans << "\n";
        else
            cout << "*\n";
    }
}