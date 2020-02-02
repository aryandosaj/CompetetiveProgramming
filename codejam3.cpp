#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t, x = 0;
    cin >> t;
    while (t--)
    {
        x++;
        ll n, l;
        cin >> n >> l;
        ll arr[l];
        ll v[l + 1];
        for (ll i = 0; i < l; i++)
            v[i] = -1;
        ll last = -1;
        set<ll> s;
        for (ll i = 0; i < l; i++)
        {
            cin >> arr[i];
            if (i != 0)
            {
                ll x = __gcd(arr[i], arr[i - 1]);
                if (x != arr[i])
                {
                    last = x;
                    s.insert(x);
                    v[i] = x;
                }
                else if (last != -1)
                {
                    v[i] = arr[i - 1] / last;
                    last = v[i];
                    s.insert(last);
                }
            }
        }
        v[l] = arr[l - 1] / last;
        s.insert(v[l]);
        ll k = 0;
        while (v[k] == -1)
            k++;

        last = v[k];
        for (ll i = k - 1; i >= 0; i--)
        {
            v[i] = arr[i] / last;
            last = v[i];
            s.insert(last);
        }



        unordered_map<ll, char> mp;
        char a = 'A';
        string ans = "";
        for (auto i : s)
            mp[i] = a++;
        for (ll i = 0; i <= l; i++)
            ans.push_back(mp[v[i]]);
        cout << "Case #" << x << ": ";
        cout << ans << "\n";
    }
}