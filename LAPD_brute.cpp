#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll a, b, c, u, d, j, t, i, p, m;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        u = b;
        a--;
        c--;
        p = 0;
        m = 0;
        for(i=0;i<100000000;i++)p++;
        cout << 0 << "\n";
    }
}