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
#define M 500005
ll bit[500005];
void upd(ll a)
{
    for (int i = a; i < M; i += i & -i)
        bit[i] += 1;
}
ll query(ll a)
{
    ll r = 0;
    for (ll i = a-1; i > 0; i -= i & -i)
        r += bit[i];
    return r;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll n = s.length();
    vll k;
    for (int i = 0; i < n; i++)
    {
        k.push_back(query(s[i]));
        upd(s[i]);
    }
    // for (int i = 0; i < M; i++)
    //     bit[i] = 0;
    // vll l;
    // for (int i = 0; i < n; i++)
    // {
    //     l.push_back(query(s[n - 1 - i]));
    //     upd(s[n - 1 - i]);
    // }
    // reverse(l.begin(), l.end());
    // vll ans;
    // for (int i = 0; i < n; i++)
    //     ans.push_back(min(k[i], l[i]));
    for (int i = 0; i < n; i++)
    {
        // cout<<k[i]<<" ";
        if (k[i])
            cout << "Ann\n";
        else
            cout << "Mike\n";
    }
}