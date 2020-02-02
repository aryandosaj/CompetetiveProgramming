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
int tree[4000005];
struct dt
{
    int a, i;
};
bool comp(dt a, dt b)
{
    if (a.a < b.a)
        return 1;
    else if (a.a == b.a)
        return (a.i > b.i);
    else
        return 0;
}
int query(int qlow, int qhigh, int low, int high, int pos)
{
    if ((high < qlow) || (qhigh < low))
        return 0;
    else if ((high <= qhigh) && (low >= qlow))
    {
        return tree[pos];
    }
    else
    {
        int mid = (low + high) / 2;
        return max(query(qlow, qhigh, low, mid, 2 * pos + 1), query(qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
}
void update(int i, int low, int high, int pos, int val)
{

    if ((i < low) || (i > high))
        return;
    if (low == high)
    {
        tree[pos] = val;
        return;
    }
    int mid = (low + high) / 2;
    if ((i >= low) && (i <= high)) //inside
    {
        update(i, low, mid, 2 * pos + 1, val);
        update(i, mid + 1, high, 2 * pos + 2, val);
        tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
        return;
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<dt> arr;


        for (ll i = 0; i < 4000005; i++)
        {
            tree[i] = 0;
        }

        for (ll i = 0; i < n; i++)
        {
            dt temp;

            cin >> temp.a;
            temp.i = i;
            arr.push_back(temp);
        }
        int l;
        cin >> l;
        int ans = -1;
        sort(arr.begin(), arr.end(), comp);
        for (ll i = 0; i < n; i++)
        {
            int r;
            if (arr[i].i == 0)
                r = 0;
            else
                r = query(0, arr[i].i - 1, 0, n - 1, 0);
            if (r == (l - 1))
            {
                ans = arr[i].a;
                break;
            }
            update(arr[i].i, 0, n - 1, 0, r + 1);
        }
        
            cout << ans << "\n";
        
    }
}