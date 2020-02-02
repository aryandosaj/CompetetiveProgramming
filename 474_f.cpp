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

struct node
{
    map<ll, ll> mp;
    ll g;
};

node tree[400005];
void make_tree(ll low, ll high, ll pos)
{
    if (low == high)
    {
        tree[pos].mp[arr[low]]++;
        tree[pos].g = arr[low];
        return;
    }
    ll mid = (low + high) / 2;
    make_tree(low, mid, 2 * pos + 1);
    make_tree(mid + 1, high, 2 * pos + 2);
    ll flag = 0;
    if (!((tree[2 * pos + 1].mp.size() == 0) || (tree[2 * pos + 2].mp.size() == 0)))
    {

        for (auto i : tree[2 * pos + 1].mp)
        {
            flag = 0;
            for (auto j : tree[2 * pos + 2].mp)
            {
                if ((j.first % i.first) != 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                tree[pos].mp[i.first] += i.second;
            }
        }
        for (auto i : tree[2 * pos + 2].mp)
        {
            flag = 0;
            for (auto j : tree[2 * pos + 1].mp)
            {
                if ((j.first % i.first) != 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                tree[pos].mp[i.first] += i.second;
            }
        }
        tree[pos].g = __gcd(tree[2 * pos + 1].g, tree[2 * pos + 2].g);
    }
    else
    {
        if (tree[2 * pos + 1].mp.size() != 0)
        {
            for (auto i : tree[2 * pos + 1].mp)
            {
                if (((tree[2 * pos + 2].g) % i.first) == 0)
                {
                    tree[pos].mp[i.first]+=i.second;
                }
            }
            tree[pos].g = __gcd(tree[2 * pos + 1].g, tree[2 * pos + 2].g);
        }
        else if((tree[2 * pos + 2].mp.size() != 0))
        {
             for (auto i : tree[2 * pos + 2].mp)
            {
                if (((tree[2 * pos + 1].g) % i.first) == 0)
                {
                    tree[pos].mp[i.first]+=i.second;
                }
            }
            tree[pos].g = __gcd(tree[2 * pos + 1].g, tree[2 * pos + 2].g);
        }
        else
        {
            tree[pos].g = __gcd(tree[2 * pos + 1].g, tree[2 * pos + 2].g);
        }
    }
    return;
}
node rangeminquery(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
    if ((qlow <= low) && (qhigh >= high)) //comleteOverlap
    {
        return tree[pos];
    }
    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        node temp;
        temp.g=0;
        return temp;
    }
    ll mid = (high + low) / 2;

    node t1 = rangeminquery(qlow, qhigh, low, mid, 2 * pos + 1);
    node t2 = rangeminquery(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    node t3;
    ll flag = 0;
    if (!((t1.mp.size() == 0) || (t2.mp.size() == 0)))
    {

        for (auto i : t1.mp)
        {
            flag = 0;
            for (auto j : t2.mp)
            {
                if ((j.first % i.first) != 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                t3.mp[i.first] += i.second;
            }
        }
        for (auto i : t2.mp)
        {
            flag = 0;
            for (auto j : t1.mp)
            {
                if ((j.first % i.first) != 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                t3.mp[i.first] += i.second;
            }
        }
        t3.g = __gcd(t1.g, t2.g);
    }
    else
    {
        if (t1.mp.size() != 0)
        {
            for (auto i : t1.mp)
            {
                if (((t2.g) % i.first) == 0)
                {
                    t3.mp[i.first]+=i.second;
                }
            }
            t3.g = __gcd(t1.g, t2.g);
        }
        else if((t2.mp.size() != 0))
        {
             for (auto i : t2.mp)
            {
                if (((t1.g) % i.first) == 0)
                {
                    t3.mp[i.first]+=i.second;
                }
            }
            t3.g = __gcd(t1.g, t2.g);
        }
        else
        {
            t3.g = __gcd(t1.g, t2.g);
        }
    }
    
    return t3;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    make_tree(0, n - 1, 0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        node mp = rangeminquery(l, r, 0, n - 1, 0);
        ll freed = 0;
        for (auto i : mp.mp)
        {
            freed += i.second;
            // cout << i.first << " ";
        }
        cout << (r - l + 1 - freed) << "\n";
    }
}