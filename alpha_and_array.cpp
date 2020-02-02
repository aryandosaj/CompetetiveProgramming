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
    ll a[n], d[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> d[i];
    ll res = 0,c=0;
    for(ll i=0;i<n;i++)
    {
        res=0;
        for(ll j=c;j<=i;j++)
        {
            if(a[c]==0)c++;
            if(a[j]>d[i])
            {
                a[j]-=d[i];
                res+=d[i];
            }
            else
            {
                res+=a[j];
                a[j]=0;
            }

        }
        cout<<res<<" ";
    }
}