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
#define p second.first
#define m second.second
ll pre[5003];
pair<ll, pair<ll, ll>> arr[5003];
set<pair<ll, ll>> s;
vll mm[5003];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        s.clear();
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++)
            mm[i].clear(),pre[i]=0;
        for (int i = 0; i < n; i++)
            cin >> arr[i].m >> arr[i].p, arr[i].first = i, mm[arr[i].m].push_back(i);

        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + mm[i - 1].size();
        }
        ll b = 0, cost = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (auto j : mm[i])
                s.insert({arr[j].p, arr[j].first});
            if (pre[i] + b < i)
            {
                int c = i - pre[i] - b;
                while (c)
                {
                    ll temp = (*(s.begin())).first;
                    s.erase(s.begin());
                    c--;
                    cost += temp;
                    b++;
                }
            }
        }
        cout << cost << "\n";
    }
}