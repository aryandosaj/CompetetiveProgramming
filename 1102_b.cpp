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
    ll n;
    ll k;
    cin >> n >> k;
    ll arr[n];
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x;

        cin >> x;
        mp[x]++;
        arr[i] = x;
    }
    
    for (auto i : mp)
    {
        if (i.second > k)
        {
            cout << "NO";
            return 0;
        }
    }
    vll ans;
    ll c = 1;
    map<ll, map<ll, ll>> col;
    for (ll i = 0; i < n; i++)
    {
        if (c == (k+1))
            c = 1;
        if (col[arr[i]][c] == 0)
        {
            col[arr[i]][c] = 1;
            ans.push_back(c);
            c++;
        }
        else
        {
            ll f = c;
            while (col[arr[i]][f] != 0)
            {
                if (f >=k)
                    f = 0;
                f++;
            }
            ans.push_back(f);col[arr[i]][f]=1;
        }
    }
    cout << "YES\n";
    for(ll i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}