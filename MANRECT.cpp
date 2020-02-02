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
    //    ios_base::sync_with_stdio(0);
    //    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll A, B, C, D, p, x, y, q;
        cout << "Q 0 0" << endl;
        cin >> B;
        // cout << "Q 0 1000000000" << endl;
        // cin >> C;
        cout << "Q 1000000000 0" << endl;
        cin >> A;
        cout << "Q 1000000000 1000000000" << endl;
        cin >> D;
        if (B > A)
        {
            cout << "Q " << (1000000000 + (B - A)) / 2 << " 0" << endl;
            cin >> p;
            y = B - p;
            x = y - (B - A);
            q = D - x;
            q = 1000000000 - q;
            x = 1000000000 - x;
            cout <<"A "<< y << " " << p << " " << x << " " << q << endl;
            ll ans;
            cin >> ans;
            if (ans == 1)
                continue;
            else
                return 0;
        }
        else
        {
            cout << "Q " << (1000000000 - (A - B)) / 2 << " 0" << endl;
            cin >> p;
            y = B - p;
            x = A - p;
            q = D - x;
            q = 1000000000 - q;
            x = 1000000000 - x;
            cout <<"A "<< y << " " << p << " " << x << " " << q << endl;
            ll ans;
            cin >> ans;
            if (ans == 1)
                continue;
            else
                return 0;
        }
    }
}