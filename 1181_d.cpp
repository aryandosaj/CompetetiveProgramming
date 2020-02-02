#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
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

ll f[500000];
bool comp(dt a, dt b)
{
    if (a.a == b.a)
        return a.i < b.i;
    else
        return a.a < b.a;
}
bool comp2(dt a, dt b)
{
    return a.a < b.a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    ll arr[n];
    dt a[m + 1];
    a[0].a = 0;
    a[0].i = 0;
    dt query[q];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        f[arr[i]]++;
    }
    for (ll i = 0; i < q; i++)
        cin >> query[i].a, query[i].a -= n, query[i].i = i;
    sort(query, query + q, comp);
    for (ll i = 1; i <= m; i++)
    {
        a[i].a = f[i];
        a[i].i = i;
    }
    sort(a, a + m + 1, comp);
    typedef tree<ll, null_type, less<ll>, rb_tree_tag,
                 tree_order_statistics_node_update>
        new_data_set;
    new_data_set s;
    ll ans[q + 1];
    ll ind = 0;
    ll sum = 0, last = 0;
    for (ll i = 1; i < m; i++)
    {
        // cout << a[i].i << " ";
        s.insert(a[i].i);
        last = sum;
        ll dif = a[i + 1].a - a[i].a;
        sum += dif * i;
        // cout << sum << " " << query[ind].a << "\n";
        while (query[ind].a <= sum)
        {
            ll temp = query[ind].a - last;
            temp = temp % (i);
            
            if (temp == 0)
                temp = i;
                temp--;
            // cout << temp << "\n";
            ans[query[ind].i] = *s.find_by_order(temp);
            ind++;
            if (ind == q)
                break;
        }
        if (ind == q)
            break;
    }
    s.insert(a[m].i);
    while (ind < q)
    {

        ll temp = query[ind].a - sum;
        
        temp = temp % (m);
        if (temp == 0)
            temp = m;
        temp--;
        // cout<<temp<<" ==";
        ans[query[ind].i] = *s.find_by_order(temp);
        ind++;
    }
    for (ll i = 0; i < q; i++)
        cout << ans[i] << "\n";
}