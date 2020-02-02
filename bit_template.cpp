#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define MAX 1000000007
ll bit[1000005];
void insert(ll u, ll val)
{
    for (int i = u; i < 1000005; i += (i & -i))
        bit[i] += val;
}
ll query(ll u)
{
    ll ret = 0;
    for (int i = u; i > 0; i -= (i & -i))
        ret += bit[i];
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}