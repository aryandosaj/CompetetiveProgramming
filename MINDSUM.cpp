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


ll sod(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        queue<ll> q;
        q.push(n);
        map<ll, ll> mp;
        mp[n] = 1;
        ll m_step = MAX;
        ll ans = MAX, step = 0;
        ll counter = 0;
        map<ll, ll> level;
        level[n] = 0;
        while (!q.empty())
        {
            ll c = q.front();
            // cout<<c<<" ";
            mp[c] = 1;
            if (ans > c)
            {
                // cout<<"here";
                ans = c;
                step = counter;
            }
            q.pop();
            if (mp[sod(c)] == 0)
            {
                q.push(sod(c));
                level[sod(c)] = level[c] + 1;
                mp[sod(c)] = 1;
            }
            if ((mp[sod(c + d)] == 0) && (mp[c + d] == 0))
            {
                q.push(c + d);
                level[c + d] = level[c] + 1;
                // mp[sod(n + d)] = 1;
                mp[c + d] = 1;
            }
            counter++;
        }
        cout << ans << " " << level[ans] << "\n";
    }
}