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
    ll v, i;
};
vector<dt> arr;
ll tree[400005];
bool comp(dt a, dt b)
{
    return a.v < b.v;
}
void update(ll low, ll high, ll q, ll ind, ll pos)
{
    if (q < low)
        return;
    if (q > high)
        return;
    if (low == high)
    {
        tree[pos] = ind;
        return;
    }
    ll mid = (low + high) / 2;
    if (q <= mid)
        update(low, mid, q, ind, 2 * pos + 1);
    else
        update(mid + 1, high, q, ind, 2 * pos + 2);
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}
ll rangeminquery(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
    if ((qlow <= low) && (qhigh >= high)) //comleteOverlap
    {
        return tree[pos];
    }
    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        return -1;
    }
    ll mid = (high + low) / 2;
    return max(rangeminquery(qlow, qhigh, low, mid, 2 * pos + 1), rangeminquery(qlow, qhigh, mid + 1, high, 2 * pos + 2));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        dt temp;
        cin >> temp.v, temp.i = i, arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), comp);
    ll ans[n];
    ans[arr[0].i] = -1;
    vll ind;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i].v > arr[i - 1].v)
        {
            update(0, n - 1, arr[i - 1].i, arr[i - 1].i, 0);
            for (auto k : ind)
                update(0, n - 1, k, k, 0);
            ind.clear();
        }
        else
            ind.push_back(arr[i - 1].i);

        ll q = rangeminquery(arr[i].i + 1, n - 1, 0, n - 1, 0);
        if (q > arr[i].i)
            ans[arr[i].i] = (q - arr[i].i - 1);
        else
            ans[arr[i].i] = -1;
    }
    for (ll i = 0; i < n; i++)
        cout << ans[i] << " ";
}