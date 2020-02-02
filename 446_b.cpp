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
#define MAX 100000000000000007
ll r[2001];
ll c[2001];
ll ans1[1000001];
ll ans2[1000001];
priority_queue<ll>a;
priority_queue<ll>b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k, p;
    cin >> n >> m >> k >> p;

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            r[i] += x;
            c[j] += x;
        
        }
    for(ll i=0;i<n;i++)
    a.push(r[i]);
    for(ll i=1;i<=k;i++)
    {
        ll temp = a.top();a.pop();
        ans1[i] = ans1[i-1]+temp;
        a.push(temp-p*m);
    }
    for(ll i=0;i<m;i++)
    b.push(c[i]);
    for(ll i=1;i<=k;i++)
    {
        ll temp = b.top();b.pop();
        ans2[i] = ans2[i-1]+temp;
        b.push(temp-p*n);
    }
    ll ans=-MAX;
    for(ll i=0;i<=k;i++)
    {
        ans = max(ans,ans1[i]+ans2[k-i]-i*(k-i)*p);
    }
    cout<<ans;
}