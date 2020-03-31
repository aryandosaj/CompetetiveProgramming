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
map<ll, ll> mp;
priority_queue<ll, vector<ll>, greater<ll>> pq;
priority_queue<ll, vector<ll>, greater<ll>> p;
ll second_element()
{
    ll x = p.top();
    p.pop();
    ll r = p.top();
    p.push(x);
    return r;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    set<ll> s;
    f(0, n)
    {
        ll a;
        cin >> a;
        p.push(a);
    }
    while (!p.empty())
    {
        if (p.size() == 1)
        {
            s.insert(p.top()), p.pop();
            continue;
        }
        if (p.top() == second_element())
        {
            ll x = p.top();
            p.pop();
            p.pop();
            p.push(x + 1);
        }
        else
            s.insert(p.top()), p.pop();
    }
    // for (auto i : s)
    //     cout << i << " ";
    // cout << "\n";
    
    ll last = *prev(s.end());
    cout << last+1 - (ll)s.size();
}