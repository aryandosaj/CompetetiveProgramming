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
struct dt
{
    ll a, i;
};
bool comp(dt a, dt b)
{
    if (a.a != b.a)
        return a.a < b.a;
    else
        a.i < b.i;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n, k, nn;
    cin >> n >> k;
    nn = n;
    vector<dt> arr;
    set<ll> s;
    queue<dt> q;
    ll xx=0;
    unordered_map<ll,ll>mp;
    for (ll i = 0; i < n; i++)
    {
        dt temp;
        cin >> temp.a;xx+=temp.a;mp[temp.a]++;
        temp.i = i + 1;
        arr.push_back(temp);
        s.insert(temp.a);
    }
    if(xx<k){cout<<"-1";return 0;}
    if(xx==k)return 0;
    ll x = 0,jj=0;
    for (auto j : s)
    {
        if ((j - x) * n <= k)
        {
            ll u = 0;
            k -= (j - x) * n;
            u+=mp[j];
            x = j;
            jj=j;
            n -= u;
        }
        else
            break;
    }
    ll g = k % n;
    jj+=(k/n);
    for (ll i = 0; i< nn; i++)
    {
        if (arr[i].a > jj)
            arr[i].a-=jj,q.push(arr[i]);
    }

    for (ll h = 0; h < g; h++)
    {
        dt a = q.front();
        q.pop();
        a.a--;
        if (a.a > 0)
            q.push(a);
    }
    while (!q.empty())
    {
        cout << q.front().i << " ";
        q.pop();
    }
}