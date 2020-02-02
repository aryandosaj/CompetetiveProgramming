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
ll ans[1001];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q, k;
    cin >> q >> k;
    for (ll i = 1; i <= 1000; i++)
    {
        
        for (ll j = i-1; j > 0; j--)
            ans[i] =(ans[i]+ __gcd(i, j))%MAX;
        ans[i]=(ans[i-1]+ans[i])%MAX;
    }

    while (q--)
    {
        ll n;
        cin >> n;
        ll t = ((n)*(n-1))/2;
        cout << (ans[n]*power(t,MAX-2,MAX))%MAX << "\n";
    }
}