#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
vll graph[105];
ll flag;
ll n;
bool chk(ll u, ll start, ll stop)
{
    if (start > stop)
        swap(start, stop);
    for (ll i = start; i <= stop; i++)
    {
        if (u == i)
            return 1;
    }

    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m;
    cin >> n >> m;
    string s = "";
    vector<pair<ll, ll>> vv;
    for (ll j = 1; j <= m; j++)
    {
        ll f = 1;
        ll start, stop;
        cin >> start >> stop;
        if (start > stop)
            swap(start, stop);

        for (ll i = start + 1; i < stop; i++)
        {
            for (auto u : graph[i])
                f *= chk(u, start, stop);
        }
        if (f)
        {
            s.push_back('i');
            graph[start].push_back(stop);
            graph[stop].push_back(start);
        }
        else
        {
            vv.push_back({start, stop});
            s.push_back('o');
        }
    }
    for (ll i = 0; i < 101; i++)
        graph[i].clear();
    for (auto j : vv)
    {
        ll f = 1;
        ll start, stop;
        start = j.first;
        stop = j.second;
        if (start > stop)
            swap(start, stop);
        for (ll i = start + 1; i < stop; i++)
        {
            for (auto u : graph[i])
                f *= chk(u, start, stop);
        }

        if (f)
        {
            graph[start].push_back(stop);
            graph[stop].push_back(start);
        }
        else
        {
            cout << "Impossible";
            return 0;
        }
    }
    cout << s;
}