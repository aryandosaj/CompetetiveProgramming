#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert    
#define vll vector<ll>
#define MAX 1000000007
ll fact[1000001];
ll a, b, n;

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
bool isGood(ll num)
{
    while (num > 0)
    {
        if (!((num % 10 == a) || (num % 10 == b)))
            return 0;
        num /= 10;
    }
    return 1;
}
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;

        // Multiply 'a' with 2
        a = (a * 2) % mod;

        // Divide b by 2
        b /= 2;
    }

    // Return result
    return res % mod;
}

ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}
ll fun(ll in)
{
    ll ans = 1;
    ans=mulmod(mulmod(fact[n],modInverse(fact[n-in],MAX),MAX),modInverse(fact[in],MAX),MAX);
    return ans;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    fact[0]=1;
    fact[1]=1;
    for(ll i = 2; i < 1000001; i++)
    {
        fact[i]=(fact[i-1]*i)%MAX;
    }
    
    cin >> a >> b >> n; 
    ll ans = 0;
    // vll ind;
    for (ll i = 0; i <= n; i++)
    {
        if (isGood(i * a + (n - i) * b))
        {
            // cout<<i<<" ";
            ans+=fun(i);
            ans=ans%MAX;
        }
    }
    // cout << ind.size() << " ";
    // for (ll i = 0; i < ind.size(); i++)
    // {
    //     ans += fun(ind[i]);
    //     // cout<<ans<<" ";
    //     ans %= MAX;
    // }
    cout << ans;
}