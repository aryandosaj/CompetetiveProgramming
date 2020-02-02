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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        double coin = 10, turkez = 0;
        double initial_rate = -1;
        for (ll i = 0; i < n; i++)
        {
            double ch, co, rate;
            cin >> ch >> co >> rate;
            if ((i == n - 1) && (ch == 2))
            {
                cout << "0\n";
                fflush(stdout);
                continue;
            }
            if (ch == 2)
            {
                if (coin <= 0)
                    cout << 0 << "\n";
                else if (rate > 0.0005)
                {
                    double selling = min(co - 0.0000001, coin);
                    coin -= selling;
                    cout << setprecision(12) << selling << "\n";
                    double temp = selling * rate;
                    turkez += temp - temp * 0.0005;
                    initial_rate = rate;
                }
                else
                    cout << "0\n";
            }
            else
            {
                if (turkez <= 0)
                    cout << "0\n";
                else if ((rate < (initial_rate + 0.0005))||(i==n-1))
                {
                    double buy = min(co - 0.0000001, turkez / rate);
                    cout << setprecision(12) << buy << "\n";
                    coin += (buy - buy * 0.0005);
                    turkez -= buy * rate;
                }
                else
                    cout << "0\n";
            }
            fflush(stdout);
        }
    }
}