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
vector<ll> prefix_function(string s)
{
    ll n = (ll)s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
string fun(string s)
{

    ll l = s.length();
    ll ind = 0;
    while (ind <= l / 2)
    {
        if (s[ind] != s[l - ind - 1])
            break;
        ind++;
    }
    string ss = "";
    f(ind, l - ind) ss.pb(s[i]);
    if (ss.size() == 0)
        return s;
    string x = ss + "#";
    reverse(ss.begin(), ss.end());
    x += ss;
    vll v = prefix_function(x);
    ll y = x.length() - 1;
    ll a = v[y];
    // cout<<x<<"\n";
    reverse(ss.begin(), ss.end());
    string ans = s.substr(0, ind) + ss.substr(0, a) + s.substr(l - ind, ind);
    // cout<<ans<<"\n";
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
        string s;
        cin >> s;
        string a1 = fun(s);
        reverse(s.begin(), s.end());
        string a2 = fun(s);
        if (a1.length() >= a2.length())
            cout << a1 << "\n";
        else
            cout << a2 << "\n";
    }
}