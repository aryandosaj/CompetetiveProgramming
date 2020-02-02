#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
ll arr[100005];
ll pre_a[100005];
ll pre_b[100005];
struct dt
{
    ll a, b;
};
bool comp(dt a, dt b)
{
    if (a.a != b.a)
        return a.a < b.a;
    else
        return a.b < b.b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre_a[i] = pre_a[i - 1] + (arr[i] == 1);
        pre_b[i] = pre_b[i - 1] + (arr[i] == 2);
    }
    vector<dt> v;
    for (ll t = 1; t <= n; t++)
    {
        ll pos = 0, ta = t, tb = t, f = 0, s_a = 0, s_b = 0, last_pos = 0;
        while (pos < n)
        {
            ll na = lower_bound(pre_a, pre_a + n + 1, ta) - pre_a;
            ll nb = lower_bound(pre_b, pre_b + n + 1, tb) - pre_b;
            if (na < nb)
                s_a++;
            else
                s_b++;
            pos = min(na, nb);
            ta = pre_a[pos] + t;
            tb = pre_b[pos] + t;
            if (pos == n)
            {
                if (na < nb && s_a > s_b)
                    f = 1;
                if (nb < na && s_b > s_a)
                    f = 1;
            }
            // cout<<na<<" "<<nb<<" "<<ta<<" "<<tb<<" "<<pos<<"\n";
        }
        // cout<<"\n";
        if (f)
            v.push_back({max(s_a, s_b), t});
    }
    sort(v.begin(), v.end(), comp);
    cout << v.size() << "\n";
    for (auto i : v)
        cout << i.a << " " << i.b << "\n";
}