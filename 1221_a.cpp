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
map<ll, ll> mp;
bool dfs(ll n)
{
    if (n == 0)
        return 0;
    if (mp[n] > 0)
    {
        mp[n]--;
        return 1;
    }
    bool ans = 1;
    ans = ans & dfs(n / 2);
    ans = ans & dfs(n / 2);
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {
        mp.clear();
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mp[x]++;
        }
        if (dfs(2048))
            cout << "YES\n";
        else
            cout<<"NO\n";   
    }
}