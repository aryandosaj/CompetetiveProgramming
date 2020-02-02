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
vector<ll>v;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll start=1, end, sum = 0;
    ll cur = 0;
    arr[0]=0;
    ll s=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        s+=arr[i];
    }   
}