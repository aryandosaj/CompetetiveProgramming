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
    string s;
    cin >> s;
    ll x = 0, y = 1;
    while (s.compare("start") == 0)
    {

        ll mm = MAX;

        while (1)
        {
            cout << "? " << x << " " << y << "\n"
                 << flush;
            char t;
            cin >> t;
            if (t == 'e')
                return 0;
            if (t == 'x')
            {
                ll m;
                while (x+1<y)
                {
                    m = (x + y) / 2;
                    cout << "? " << x << " " << m << "\n"
                         << flush;
                    cin >> t;
                    if (t == 'x')
                        y = m;
                    else
                        x = m;
                }
                cout<<"! "<<y<<"\n";x=0;y=1;break;
            }
            else
            {
                x = y;
                y = min(y * 2, mm);
            }
        }
        cin >> s;
    }
    // fflush(stdout);
}