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

struct dt
{
    ll p, b, n, e;
};
bool comp(dt a, dt b)
{
    return a.p < b.p;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll b, n, e;
    ll sb, sn, se;
    ll m;
    cin >> b >> n >> e >> sb >> sn >> se;
    m = (b + n + e) / 2;
    ll c[m];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    
    sort(c, c + m);
    ll l = 0, h = MAX;
    ll mid;
    dt p[6];
    p[0] = {2 * sb, 2, 0, 0};
    p[1] = {sb + sn, 1, 1, 0};
    p[2] = {2 * sn, 0, 2, 0};
    p[3] = {sn + se, 0, 1, 1};
    p[4] = {se + se, 0, 0, 2};
    p[5] = {sb + se, 1, 0, 1};
    sort(p, p + 6,comp);
    ll ans=0;
    while (l <= h)
    {
        ll bb = b, nn = n, ee = e;
        mid = (l + h) / 2;
        ll flag = 0;
        for (int i = 0; i < m; i++)
        {
            ll f = 0;
            for (int j = 0; j < 6; j++)
            {
                if (p[j].p * c[i] >= mid)
                {
                    if (p[j].b <= bb && p[j].n <= nn && p[j].e <= ee)
                    {
                        f = 1;
                        bb -= p[j].b;
                        nn -= p[j].n;
                        ee -= p[j].e;
                        break;
                    }
                }
            }
            if (!f)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            h = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    cout<<ans;
}