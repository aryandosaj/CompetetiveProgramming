#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    double a, b,z;
    cin >> n >> m >> a >> b >> z;
    vector<double> d;
    for (ll i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        d.push_back(sqrt((x - a) * (x - a) + (y - b) * (y - b)));
    }
    sort(d.begin(), d.end());
    m--;
    // cout<<d[m];
    if(z<d[m]){cout<<"NO";return 0;}
    if (d[m] == d[m + 1])
    {
        cout << "NO";
    }
    else
        cout <<"YES";
}
