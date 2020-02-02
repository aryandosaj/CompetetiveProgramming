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
    ll l, r, s;
};
struct dt2
{
    ll i, v, u;
};
bool comp(dt a, dt b)
{
    if (a.s == b.s)
    {
        if (a.r == b.r)
        {
            return a.l > b.l;
        }
        else
        {
            return a.r > b.r;
        }
    }
    else
    {
        return a.s > b.s;
    }
}
bool comp2(dt2 a, dt2 b)
{
    return a.i < b.i;
}
bool comp3(dt2 a, dt2 b)
{
    return a.v > b.v;
}
ll arr[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, q;
        cin >> n >> m >> q;
        
        vector<dt> v;
        vector<dt2> que;
        for (ll i = 0; i <= m; i++)
            arr[i] = 0;
        for (ll i = 0; i < n; i++)
        {
            ll l, r;
            cin >> l >> r;
            arr[l]++;
            if (r + 1 <= m)
                arr[r + 1]--;
        }
        for (ll i = 1; i <= m; i++)
            arr[i] += arr[i - 1];

        for (ll i = 1; i <= m; i++)
        {
            ll l, r, flag = 0;
            if (arr[i] == 0)
                l = i, flag = 1;
            while ((i<=m)&&(arr[i] == 0))
                i++;
            r = i - 1;
            dt temp;
            temp.l = l;
            temp.r = r;
            temp.s = (r - l + 1);

            if (flag)
                v.push_back(temp);
        }
        for (ll i = 0; i < q; i++)
        {
            dt2 temp;
            temp.i = i;
            cin >> temp.v;
            que.push_back(temp);
        }
        sort(v.begin(), v.end(), comp);
        sort(que.begin(), que.end(), comp3);
        ll l = 0, r = 0, siz = v[0].s;
        ll j = 0;
        for (ll i = 0; i < que.size(); i++)
        {

            while ((j < v.size())&&(v[j].s >= que[i].v))
            {
                if (v[j].r > r)
                {
                    r = v[j].r;
                    l = v[j].l;
                }
                else if ((v[j].r == r) && (v[j].l > l))
                {
                    l = v[j].l;
                }
                j++;
            }
            // cout << l << " " << r << "\n";
            if (que[i].v < (r - l + 1))
                que[i].u = r - (que[i].v) + 1;
            else
                que[i].u = l;
            que[i].v = r;
        }
        sort(que.begin(), que.end(), comp2);
        for (ll i = 0; i < que.size(); i++)
        {
            if (que[i].u == 0)
                cout << "-1 -1\n";
            else
            {

                cout << que[i].u << " " << que[i].v << "\n";
            }
        }
    }
}