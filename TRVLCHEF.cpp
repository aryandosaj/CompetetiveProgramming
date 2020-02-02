#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, d;
        cin >> n >> d;
        ll c[n], root;
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> c[i];
            mp[c[i]]++;
            if (!i)
                root = c[i];
        }
        sort(c, c + n);
        ll f = 0;
        ll pos = lower_bound(c, c + n, root) - c;
        if ((pos != n - 1) && (pos != 0))
        {
            ll pos2 = lower_bound(c, c + n, root - d) - c;
            ll pos3 = upper_bound(c, c + n, root + d) - c;
            pos3--;
            if (((pos - pos2 >= 2) || (pos == 1)) || ((pos3 - pos >= 2) || (pos == n - 2)))
            {
                if (c[pos + 1] - c[pos - 1] > d)
                {
                    f = 1;
                }
            }
            // if(pos==1)
        }
        if (f)
        {
            cout << "NO\n";
            continue;
        }
        ll flag = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            if (c[i + 1] - c[i] > d)
            {
                flag = 1;
                cout << "NO\n";
                break;
            }
        }
        if (!flag)
            cout << "YES\n";
    }
}