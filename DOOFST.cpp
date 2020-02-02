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
ll num;
void pr(ll n,ll k)
{
    queue<pair<ll, pair<ll, pair<ll,ll>>>> q;
    ll m = (1+n) / 2;
    q.push({1, {m, {0,1}}});
    q.push({m+1, {n, {1,1}}});
    while (!q.empty())
    {
        ll start = q.front().first;
        ll stop = q.front().second.first;
        ll h = q.front().second.second.first;
        ll d = q.front().second.second.second;
        q.pop();
        for (int i = start; i <= stop; i++)
        {
            cout << h;
        }
        if (start < stop)
        {
            m = (start + stop) / 2;
            q.push({start, {m, {0,d+1}}});
            q.push({m + 1, {stop, {1,d+1}}});
        }
        else if(d<k)
        {
            q.push({start, {stop, {h,d+1}}});
        }
        
        if (stop == num)
            cout << "\n";
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    // cin >> n;

    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
    }
    num = n;
    ll k = ceil(log2(n));
    ll d = 1;
    cout << k << "\n";
    pr(n,k);
}