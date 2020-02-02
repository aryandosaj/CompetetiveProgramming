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
    ll n, k, m;
    cin >> n >> k >> m;
    vector<double> v;
    double sum = 0;
    for (ll i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        sum += x;
        v.push_back(x);
    }
    double avg = (sum / (n * 1.0));
    ll p = 0;
    sort(v.begin(), v.end());
    unordered_map<ll, ll> mp;
    double nn = n;
    ll l = nn-1;
    if(m>(n-1))
    {
        m-=(n-1);
        avg = v[nn-1]+min(m,k);
        cout<<avg;return 0;
    }
    else
    {
        ll p=0;
        for(ll i=0;i<m;i++)
        {
            if((avg+1/nn)<((avg*nn-v[p])/(nn-1)))
            {
                avg=(avg*nn-v[p])/(nn-1);p++;nn--;
            }
            else
            {
                avg+=(1/nn);
            }
            // cout<<avg<<"\n";
            
        }
    }
    cout<<setprecision(15)<<avg;
    
}