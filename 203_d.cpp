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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a, b, m, vx, vy, vz, T;
    cin >> a >> b >> m >> vx >> vy >> vz;
    double t = -1 * (m / vy);
    double x = a / 2;
    double z = 0;
    if (vx != 0)
    {
        double tx = abs(2 * a / vx);

        double o = floor(t / tx);
        T = t - o * tx;
        double ta = abs(a / (2 * vx));
        double tb = abs(3 * a / (2 * vx));
        double tc = abs(2 * a / vx);
        if (T < ta)
        {
            x = a / 2 + vx * (T);
        }
        else if (T < tb)
        {
            if (vx < 0)
                x = (T - ta) * (-vx);
            else
                x = a - (T - ta) * (vx);
        }
        else
        {
            if (vx < 0)
                x = a - (T - tb) * (-vx);
            else
                x = (T - tb) * (vx);
        }
        // cout<<tb<<" "<<T<<" ";
    }
    if (vz != 0)
    {
        double to = (2 * b) / vz;
        T = t - floor(t / to) * to;
        
        if (T < (b / vz))
        {
            z = vz * T;
        }
        else
        {
            z = b - vz * (T - b / vz);
        }
    }
    cout << setprecision(15) << x << " " << z;
}