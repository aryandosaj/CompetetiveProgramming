#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, h, w, a[1010][1010];
set<ll> s;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void te()
{
    cin >> n >> m >> h >> w;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> a[i][j];
    ordered_set o_set;
    ll ans = LLONG_MAX;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            o_set.insert(a[i][j]);
        }
    }
    ans = min(ans, (ll)*o_set.find_by_order((h * w) / 2));
    for (ll i = 0; i + h <= n; i++)
    {
        for (ll j = 0; j + w < m; j++)
        {
            ll pos = 0;
            for (ll k = 0; k < h; k++)
                o_set.erase(a[i + k][j]), o_set.insert(a[i + k][j + w]);

            // for(ll o=0;o<pos;o++)
            // 	cout << arr[o] << " ";
            // cout << "\n";
            // cout << arr[pos/2] << "\n";
            ans = min(ans, (ll)*o_set.find_by_order((h * w) / 2));
        }
        o_set.clear();
        if ((h + i) < n)
        {
            for (ll p = 0; p < h; p++)
            {
                for (ll q = 0; q < w; q++)
                {
                    o_set.insert(a[p + i + 1][q]);
                }
            }
            ans = min(ans, (ll)*o_set.find_by_order((h * w) / 2));
        }
    }

    cout << ans << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);		//Comment
    // freopen("output.txt", "w", stdout);		//this out.
    ios::sync_with_stdio(false); //Not
    cin.tie(NULL);               //this.
    cout.tie(0);                 //or this.

    te();

    return 0;
}