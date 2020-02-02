#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
ll n, a, b;
ll h[15];
vll aa(1000,0);
ll fun(ll ind, vll v, vll kk)
{
    ll x =0;
    if(v[ind-1]>0)
    x= ceil(( v[ind - 1]) / (b*1.0));

    v[ind] = (v[ind] - a * x);
    v[ind + 1] = (v[ind + 1] - b * x);


    ll s = v[ind];
    ll ans = MAX;
    ll count = 0;
    for (ll i = 0; i < x; i++)
        kk.push_back(ind + 1);
    if (ind != n - 2)
    {
        vll temp = v;
        ans = fun(ind + 1, temp, kk);
        while (s > 0)
        {
            s -= a;
            count++;
            temp[ind + 1] = (temp[ind + 1] - b );
            temp[ind] =  s;
            kk.push_back(ind + 1);
            ans = min(ans, fun(ind + 1, temp, kk) + count);
        }
    }
    else
    {
        ans = (ll)max(ceil(v[ind] / (a * 1.0)), ceil(v[ind + 1] / (b * 1.0)));
        for (ll i = 0; i < ans; i++)
            kk.push_back(ind + 1);
        if (aa.size() > kk.size())
            aa = kk;
    }

    if (ans == MAX)
        ans = 0;
    return ans + x;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout<<aa.size();
    cin >> n >> a >> b;
    vll v;

    for (ll i = 0; i < n; i++)
        cin >> h[i], v.push_back(h[i] + 1);
    ll x = 0;
    vll kk;
    ll ans = fun(1, v,kk);
    cout << aa.size()<<"\n";
    for(ll i=0;i<aa.size();i++)cout<<aa[i]<<" ";
    
}