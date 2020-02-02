#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll p[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n, x, y, a, b, k;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];
        cin >> x >> a >> y >> b >> k;
        sort(p, p + n, greater<ll>());

        ll low = 0, high = n, mid, ans = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            // cout<<mid<<"\n";
            ll z = (a * b) / __gcd(a, b);
            ll n_z = mid / z;
            ll n_x = mid / a - n_z;
            ll n_y = mid / b - n_z;
            
            vector<pair<ll, ll>> v;
            v.push_back({x, n_x });
            v.push_back({y, n_y});
            v.push_back({(x + y), n_z});
            sort(v.begin(), v.end(), greater<pair<ll, ll>>());
            ll mx = 0;
            ll t = 0;
            ll f = 0;
            for (int i = 0; i < mid; i++)
            {
                // cout <<i<<" "<< mx << "\n";
                for (int j = 0; j < 3; j++)
                {
                    
                    if (v[j].second)
                    {
                        // cout<<v[j].first<<" "<<v[j].second<<"\n";
                        mx += (v[j].first * p[i]) / 100;
                        v[j].second--;
                        break;
                    }
                }
                if (k <= mx)
                {
                    f = 1;
                   
                    break;
                }
            }
            // cout << n_x <<" "<< n_y<<" " << n_z << " "<<mx<<"\n";
            if (f == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = mid;
            }
        }
        cout<<ans<<"\n";
    }
}