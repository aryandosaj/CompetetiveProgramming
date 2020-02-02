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
ll arr[100005];
struct dt
{
    ll r, g, b;
};
void display(dt a)
{
    cout<<"\n"<<a.r<<" "<<a.g<<" "<<a.b<<"\n";
}
dt tree[400005];
ll lazy[400050];
dt light(dt a, ll b)
{
    ll temp;
    b = b % 3;

    for (ll i = 0; i < b; i++)
    {
        temp = a.r;
        a.r = a.b;
        a.b = a.g;
        a.g = temp;
        
    }
    return a;
}
void update_lazy(ll qlow, ll qhigh, ll low, ll high, ll pos, ll v)
{
    
    if (lazy[pos] != 0)
    {
        tree[pos] = light(tree[pos], lazy[pos]);
        if (low != high)
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if ((qlow <= low) && (qhigh >= high)) //complete overlap
    {
        // cout<<"upfdating"<<low<<" "<<high<<"---";
        tree[pos] = light(tree[pos], 1);
        // display(tree[pos]);
        if (low != high)
        {
            lazy[pos * 2 + 1] += 1;
            lazy[pos * 2 + 2] += 1;
        }
        return;
    }

    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        return;
    }
    ll mid = (high + low) / 2;
    update_lazy(qlow, qhigh, low, mid, (2 * pos + 1), 1);
    update_lazy(qlow, qhigh, mid + 1, high, (2 * pos + 2), 1);

    tree[pos].r = tree[2 * pos + 1].r + tree[2 * pos + 2].r;
    tree[pos].b = tree[2 * pos + 1].b + tree[2 * pos + 2].b;
    tree[pos].g = tree[2 * pos + 1].g + tree[2 * pos + 2].g;
}

void build(ll low, ll high, ll pos)
{
    if (low > high)
        return;
    if (low == high)
    {
        if (arr[low] == 0)
            tree[pos].r += 1;
        else if (arr[low] == 1)
            tree[pos].g += 1;
        else
            tree[pos].b += 1;
        return;
    }
    ll mid = (low + high) >> 1;
    build(low, mid, 2 * pos + 1);
    build(mid + 1, high, 2 * pos + 2);
    tree[pos].r = tree[2 * pos + 1].r + tree[2 * pos + 2].r;
    tree[pos].b = tree[2 * pos + 1].b + tree[2 * pos + 2].b;
    tree[pos].g = tree[2 * pos + 1].g + tree[2 * pos + 2].g;
}

dt query(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
    if (lazy[pos] != 0)
    {
        tree[pos] = light(tree[pos], lazy[pos]);
        if (low != high)
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        return {0, 0, 0};
    }
    if ((qlow <= low) && (qhigh >= high)) //complete overlap
    {
        return tree[pos];
    }
    ll mid = (high + low) / 2;
    dt temp;
    dt t1, t2;
    t1 = query(qlow, qhigh, low, mid, 2 * pos + 1);
    t2 = query(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    temp.r = t1.r + t2.r;
    temp.b = t1.b + t2.b;
    temp.g = t1.g + t2.g;

    return temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    for (ll i = 0; i < 100005; i++)
    {
        arr[i] = 0;
    }

    for (ll i = 0; i < 400050; i++)
    {
        lazy[i] = 0;
        tree[i].r = 0;
        tree[i].b = 0;
        tree[i].g = 0;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, n - 1, 0);
    dt tem;
    tem.r = 1;
    tem.g = 2;
    tem.b = 3;
    tem = light(tem, 1);
    // cout << tem.r << " " << tem.g << " " << tem.b;

    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, r, c;
        ll type;
        cin >> type;
        if (type)
        {
            cin >> l >> r;
            l--, r--;
            update_lazy(l, r, 0, n - 1, 0, 1);
        }
        else
        {
            cin >> l >> r >> c;
            l--;
            r--;
            dt a = query(l, r, 0, n - 1, 0);
            if (c == 0)
                cout << a.r << "\n";
            else if (c == 1)
                cout << a.g << "\n";
            else
                cout << a.b << "\n";
        }
    }
}