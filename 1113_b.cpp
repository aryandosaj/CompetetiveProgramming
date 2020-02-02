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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        while ((num % 2) == 0)
            num /= 2, mp[2]++;
        for (ll j = 3; j <= sqrt(num); j += 2)
        {
            while ((num % j) == 0)
                num /= j, mp[j]++;
        }
        if (num > 2)
            mp[num]++;
    }

    priority_queue<ll> pq;
    for (ll i = 0; i < n; i++)
        pq.push(-1);
    vll v;
    ll mm = 0;
    for (auto i : mp)
    {
        // cout<<i.first<<" ";
        v.push_back(i.first);
        mm = main(mm, i.second);
    }

    reverse(v.begin(), v.end());
    while (mm--)
    {
        for (ll i = 0; i < v.size(); i++)
        {
            if(mp)
            {
                ll t = pq.top();
                pq.pop();
                pq.push(t * v[i]);
            }
        }
    }

    ll ans = 0;
    while (!pq.empty())
    {
        ans += pq.top() * -1;
        pq.pop();
    }
    cout << ans;
}