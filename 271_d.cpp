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
// #define MAX 18446744073709551557
ll p=53;
ll MAX = pow(2,63)-25;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, u;
    cin >> s >> u;
    // cout<<s<<" "<<u<<"\n";
    ll arr[200];
    for (char i = 'a'; i <= 'z'; i++)
        arr[i] = 1 - (u[i - 'a'] - '0');
    ll k;
    cin >> k;
    ll pre[s.length() + 1];
    pre[0] = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        pre[i + 1] = pre[i] + arr[s[i]];
    }
    string f = "";
    ll h=0;
    unordered_map<ll, bool> mp;
    ll ans = 0;
    set<ll> hh;

    // cout<<t<<"--";
    for (ll i = 0; i < s.length(); i++)
    {
        h=0;
        for (ll j = i; j < s.length(); j++)
        {
            (h+=s[j]*power(p,j-i,MAX))%=MAX;
            // if ((pre[j + 1] - pre[i])> k)break;
            if ( ((pre[j + 1] - pre[i]) <= k))
            {
                ans++;
                hh.insert(h);
            }
        }
    }
    ans = hh.size();
    cout << ans;
}