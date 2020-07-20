#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s, r;
        cin >> s >> r;
        vll v;
        priority_queue<ll> pq;

        f(0, s.length()) if (s[i] != r[i]) v.pb(i);
        if (v.size() == 0)
        {
            cout << "0\n";
            continue;
        }
        ll l = v.size();

        ll last = v[0];
        f(1, l)
            pq.push(v[i] - last - 1),
            last = v[i];    

        ll sum = v[l - 1] - v[0] + 1;
        ll ans = sum;
        ll c = 1;
        while (!pq.empty())
        {
            c++;
            ll u = pq.top();
            pq.pop();
            sum -= u;
            ans = min(ans, sum * c);
        }
        cout << ans << "\n";
    }
}