#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
ll b[100005];
double p[100005];
ll p2[33];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p2[0] = 1;
    for (ll i = 1; i < 33; i++)
        p2[i] = p2[i - 1] * 2;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        for (ll i = 0; i < n; i++)
            cin >> p[i];
        double ans = 0;
        for (ll i = 0; i < 33; i++)
        {
            double s1 = 0, s2 = 1, temp;
            for (ll j = 0; j < n; j++)
            {
                if (p2[i] & b[j])
                {
                    temp = s2;
                    s2 = s2*(1-p[j])+p[j]*s1;
                    s1 = s1*(1-p[j]) + temp*p[j];
                }
            }
            ans += ((double)p2[i]) * s1;
        }
        cout << setprecision(15) << ans << "\n";
    }
}