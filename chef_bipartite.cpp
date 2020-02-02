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
ll dig1[105];
ll dig2[105];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        for(int i=0;i<105;i++)dig1[i]=0,dig2[i]=0;
        ll n, m, d, D;
        cin >> n >> m >> d >> D;
        vector<pair<ll, ll>> v;
        for (int g = 0; m; g++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (m > 0)
                {
                    v.push_back({i, ((i + g) > n ? (i + g - n) : i + g)});
                    dig1[i]++;
                    dig2[((i + g) > n ? (i + g - n) : i + g)]++;
                    m--;
                }
                else
                    break;
            }
        }
        ll f = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dig1[i] < d || dig1[i] > D || dig2[i] < d || dig2[i] > D)
            {
                f = 1;
                break;
            }
        }
        if (f)
            cout << "-1\n";
        else
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i].first << " " << v[i].second << "\n";
            }
        }
    }
}