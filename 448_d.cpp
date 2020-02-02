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
    ll n, m, k;
    cin >> n >> m >> k;
    ll low = 1, high = n * m;
    ll mid;ll ans=high;
    while (low < high)
    {
        mid = (low + high) / 2;
        ll rank = 0;
        for (ll i = 1; i <= n; i++)
        {
            rank += min(m, mid / i);
        }
        if (rank >= k)
            high = mid;
        else
            low = mid + 1;
            // cout<<mid<<" "<<rank<<"\n";
    }
    
        cout << low;
}