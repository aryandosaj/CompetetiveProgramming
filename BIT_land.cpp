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
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vll freq[10];
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - '0'].push_back(i);
    }
    vll odd;
    for (int i = 0; i < 10; i++)
    {
        if (freq[i].size() & 1)
            odd.push_back(i);
    }
    if (odd.size() == 0)
    {
        cout << "-1\n";
        return 0;
    }
    ll last_l = 0, last_r = 100000;
    ll l = 0, r = 100000;
    ll o = odd.size();
    ll f = 0;
    while (l <= r)
    {
        ll c = 0;
        for (auto i : odd)
        {
            auto p = lower_bound(freq[i].begin(), freq[i].end(), l);
            if (p == freq[i].end()||(*p)>r)
                continue;
            else
            {
                auto q = upper_bound(freq[i].begin(), freq[i].end(), r);
                if (q == freq[i].begin()||(*(--q))<l)
                {
                    continue;
                }
                else
                {
                    c++;
                }
            }
        }
        if (c < o)
        {
            if (f == 1)
                break;
            else
            {
                f = 1;
                l = last_l;
            }
        }
        else
        {
            last_l = l;
            last_r = r;
            if (f == 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << last_r - last_l << "\n";
}