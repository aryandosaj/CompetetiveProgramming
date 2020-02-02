#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n;
        cin >> n;
        ll x[n], y[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        double num = s.length();
        if (!(floor(sqrt(num)) == sqrt(num)))
            num = pow((floor(sqrt(s.length())) + 1), 2);
        //    cout<<num<<"---";
        ll nn = (ll)sqrt(num);
        ll arr[nn + 1];

        for (ll i = 0; i < nn + 1; i++)
        {
            arr[i] = i;
        }

        for (ll i = 0; i < n; i++)
        {
            ll temp;
            temp = arr[x[i]];
            arr[x[i]] = arr[y[i]];
            arr[y[i]] = temp;
        }
        ll ii = s.length();
        for (ll i = 0; i < nn; i++)
        {

            for (ll j = 0; j < nn; j++)
            {
                if (i * nn + arr[j + 1] <= ii)
                    cout << s[i * nn + arr[j + 1] - 1];
            }
        }
        cout << "\n";
    }
}