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
vll boss[100005];
ll dad[100005];
pair<ll,ll> street[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        ll p;
        cin >> p;
        boss[p].push_back(i + 1);
        dad[i+1]=p;
    }
    for(int i=1;i<=n;i++)
    {
        ll u,v;
        cin>>u>>v;
        street[i]={u,v};
    }
    

}