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
    ll t;
    cin >> t;
    while (t--)
    {
        ll hpa, hpb, aa, ab;
        ll hpa1, hpb1;
        cin >> hpa >> hpb >> aa >> ab;
        string sa, sb;
        ll da = 0, db = 0;
        sa = "";
        sb = "";
        ll i = 1;
        hpa1 = hpa;
        hpb1 = hpb;
        while (hpa > 0)
        {
            hpa -= i;
            i++;
            sa += "A";
            da += (aa + ab);
        }
        while (hpb > 0)
        {
            hpb -= i;
            i++;
            sa += "B";
            da += (ab);
        }
        i = 1;
        while (hpb1 > 0)
        {
            hpb1 -= i;
            i++;
            sb += "B";
            db += (aa + ab);
        }
        while (hpa1 > 0)
        {
            hpa1 -= i;
            i++;
            sb += "A";
            db += (aa);
        }

        if (db < da)
            cout << db << " " << sb << "\n";
        else
            cout << da << " " << sa << "\n";
    }
}