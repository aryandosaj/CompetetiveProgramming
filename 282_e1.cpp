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
struct trie
{
    map<ll, trie> mp;
    bool end;
};
trie root;
ll MAX_LEN = 50;
void insert(trie &r, ll n)
{
    for (ll i = MAX_LEN; i >= 0; i--)
        if (n & ((ll)(pow(2, i))))

            r = r.mp[1];
        else
            r = r.mp[0];
}
ll search(trie &r, ll n)
{
    ll ans = 0;
    for (ll i = MAX_LEN; i >= 0; i--)
    {
        ll temp = pow(2, i);

        // cout<<(n&((ll)(pow(2,i))))<<" ";
        if (n & (temp))
        {
            if (r.mp.count(0))
                r = r.mp[0];
            else
                r = r.mp[1], ans += (temp);
        }
        else
        {
            if (r.mp.count(1))
                r = r.mp[1], ans += (temp);
            else
                r = r.mp[0];
        }
    }
    return ans;
}
ll pre[100005];
ll suf[100005];
ll arr[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = arr[i] ^ pre[i - 1];
        ans = max(ans, pre[i]);
    }
    for (ll i = n; i > 0; i--)
    {
        suf[i] = suf[i + 1] ^ arr[i];
        ans = max(ans, suf[i]);
    }

    for (ll i = n - 1; i > 0; i--)
    {
        insert(root, suf[i + 1]);
        ans = max(ans, pre[i] ^ search(root, pre[i]));
    }
    cout << ans;
}