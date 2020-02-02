#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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

struct ddd
{
    ll i, val;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    while (n != 0)
    {
        ll arr[n];
        vector<ddd> v1, v2;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            ddd temp;
            temp.i = i;
            temp.val = abs(arr[i]);
            if (arr[i] > 0)
            {
                v1.push_back(temp);
            }
            else if (arr[i] < 0)
                v2.push_back(temp);
        }
        ll i1 = 0;
        ll w = 0;
        ll i2 = 0;
        while ((i1 < v1.size()) || (i2 < v2.size()))
        {
            if (v1[i1].val == v2[i2].val)
            {
                w += abs(v2[i2].i - v1[i1].i) * v1[i1].val;
                i1++;
                i2++;
            }
            else if (v1[i1].val > v2[i2].val)
            {
                w += abs(v2[i2].i - v1[i1].i) * v2[i2].val;
                v1[i1].val -= v2[i2].val;
                i2++;
            }
            else
            {
                w += abs(v2[i2].i - v1[i1].i) * v1[i1].val;
                v2[i2].val -= v1[i1].val;
                i1++;
            }
        }
        cout << w << "\n";
        cin >> n;
    }
}