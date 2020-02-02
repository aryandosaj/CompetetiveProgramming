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
struct dt
{
    ll i, c;
};
bool comp(dt a, dt b)
{
    return a.c < b.c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, MSK;
    MSK = 1 << 9;
    cin >> n >> m;
    vll v, p, ing;
    unordered_map<ll, vector<dt>> exist;
    unordered_map<ll, ll> satisfy;

    for (ll i = 0; i < n; i++)
    {
        ll f;
        cin >> f;
        ll num = 0;
        for (ll i = 0; i < f; i++)
        {
            ll a;
            cin >> a;
            a--;
            num = num | (1 << a);
        }
        satisfy[num]++;
    }
    for (ll i = 0; i < m; i++)
    {
        ll cost;
        cin >> cost;
        p.push_back(cost);
        ll r, num = 0;
        cin >> r;
        while (r--)
        {
            ll a;
            cin >> a;
            a--;
            num = num | (1 << a);
        }
        exist[num].push_back({i, cost});
    }
    for (ll i = 0; i < MSK; i++)
    {
        sort(exist[i].begin(), exist[i].end(), comp);
        while (exist[i].size() > 2)
            exist[i].pop_back();
    }
    ll req = 0, ans = 0, cost = MAX, ii=0, jj=1;
    for (ll i = 0; i < MSK; i++)
    {
        for (ll j = 0; j < MSK; j++)
        {
            if ((i == j) && (exist[i].size() < 2))
                continue;
                
            if (exist[i].size() && exist[j].size())
            {
                
                ll num = i | j;
                ll curans = 0, curcost = 0, p1, p2;
                curcost = exist[i][0].c;
                p1 = exist[i][0].i;
                if (i == j)
                    curcost += exist[i][1].c, p2 = exist[i][1].i;
                else
                    curcost += exist[j][0].c, p2 = exist[j][0].i;

                    
                for (ll k = 0; k < MSK; k++)
                {
                    if ((k & num) == k)
                        curans+=satisfy[k];
                }
                // cout<<p1<<" "<<p2<<" "<<curans<<" "<<curcost<<"\n";
                if (ans < curans)
                {
                    ans = curans;
                    cost = curcost;
                    ii = p1, jj = p2;
                }
                else if (ans == curans && curcost < cost)
                {
                    cost = curcost;
                    ii = p1;
                    jj = p2;
                }
            }
            else
                continue;
        }
    }
    cout << ii+1 << " " << jj+1 << "\n";
}