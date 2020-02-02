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
struct dt
{
    ll l, r;
};
// bool comp(dt a,dt b)
// {
//     if(a.l!=b.l)
//     return a.l<b.l;
//     else
//     return a.r>b.r;
// }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    dt arr[n];
    dt pre[n];
    dt post[n];
    ll start = 0, end = MAX;
    for (ll i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        start = max(start, l);
        end = min(end, r);
        arr[i].l = l;
        arr[i].r = r;
        pre[i].l = start;
        pre[i].r = end;
    }
    start = 0, end = MAX;
    for (ll i = n - 1; i >= 0; i--)
    {
        start = max(start, arr[i].l);
        end = min(end, arr[i].r);
        post[i].l = start;
        post[i].r = end;
    }
    ll ans_l = 0, ans_r = MAX, len = 0;
    for (ll i = 0; i < n; i++)
    {
        if ((i < n - 1) && (i > 0))
        {
            ans_l = max(pre[i - 1].l, post[i + 1].l);
            ans_r = min(pre[i - 1].r, post[i + 1].r);
        }
        else if(i==0)
        {
            ans_l = post[i+1].l;
            ans_r = post[i+1].r;
        }
        else
        {
            ans_l = pre[i-1].l;
            ans_r = pre[i-1].r;
        }
        len = max(len, ans_r - ans_l);
    }
    cout<<len;
}