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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    // #endif

    cout << "a" << endl;
    ll a, b;
    cin >> a;
    string c = "";
    if (a == 300)
    {

        f(0,300)c.pb('b');
        cout<<c<<endl;
        cin>>a;
        exit(0);
    }
    f(0, a + 1) c.pb('a');
    cout << c << endl;
    cin >> b;
    if (b == 0)
        exit(0);
    if (b == a + 1)
    {
        c = "";
        f(0, a)
            c.pb('b');
        cout << c << endl;
        cin >> a;
        exit(0);
    }

    ll len = a + 1;
    string s = "";
    ll x;
    f(0, len) s.pb('a');
    x = b;
    f(0, len)
    {
        s[i] = 'b';
        cout << s << "\n";
        ll t;
        cin >> t;
        if (t > x)
            s[i] = 'a';
        if (t < x)
            x = t;
        if (x == 0)
            exit(0);
    }
}