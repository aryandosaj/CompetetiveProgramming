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
    set<pair<string, ll>> q;
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.length();
    for (ll i = 0; i < n; i++)
        q.insert({string() + s[i], i + 1});
    if ((n * (n + 1ll)) / 2 < k)
        cout << "No such line.\n";
    else
    {
        while (k--)
        {
            auto p = *q.begin();
            q.erase(q.begin());
            if (!k)
            {
                cout << p.first << "\n";
                return 0;
            }
            if (p.second < n)
                q.insert({p.first + s[p.second], p.second + 1});
        }
    }
}