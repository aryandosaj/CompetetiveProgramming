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
    ll n, x, y,c=0;
    cin >> n >> x >> y;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<=x)c++;
    }
    if(x>y)
    {
        cout<<n;return 0;
    }
    else
    {
        if(c&1)
        cout<<c/2+1;
        else
        cout<<c/2;
    }
}