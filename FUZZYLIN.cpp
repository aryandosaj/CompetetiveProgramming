#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
ll gc[100005];
ll c[100005];
unordered_map<ll, long long> f;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    ll start = 0;
    for (int r = 0; r < n; r++)
    {
        ll g = arr[r];
        for (int l = r; l >= 0; l--)
        {
            if (gc[l] != 0)
            {
                if (gc[l] == g)
                {
                    c[l]++;
                    break;
                }
            }
            else
                gc[l] = g;
            g = __gcd(g, arr[l]);

            if (g == 1)
            {
                if (l >= start)
                {
                    f[1] += (l - start + 1) * (n - r);
                    start = l + 1;
                }
                break;
            }
            else
            {
                f[g] += 1;
            }
        }
    }
    for (int r = n; r >= 0; r--)
    {
        ll g = gc[r];
        if (c[r])
            for (int l = r; l >= 0; l--)
            {
                g = __gcd(arr[l],g);
                if(g==1)break;
                if(gc[l]==g&&l!=r){c[l]+=c[r];break;}
                f[g] += c[r];

            }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        long long a = 0;
        for (int i = 1; i * i <= k; i++)
        {
            if (k % i == 0)
            {
                ll d = k / i;
                a += f[i];
                if (d != i)
                    a += f[d];
            }
        }
        cout << a << "\n";
    }
}