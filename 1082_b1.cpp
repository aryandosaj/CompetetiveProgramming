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
    string s;
    cin >> n >> s;
    vll v;
    ll G = 0, S = 0,mm=0;
    for (ll i = 0; i < n; i++)
    {
        char c = s[i];
        ll f = 0;
        while ((c == s[i])&&(i<n))
            f++, i++;
        v.push_back(f);

        i--;
        if (c == 'S')
            S++;
        if (c == 'G')
            G++,mm = max(mm,f);
    }
    // cout<<"HERE";
    if (G > 2)
    {
        ll k = 0;
        if (s[0] == 'S')
            k++;
        ll ma=0;
        for (ll i = k+1; i < v.size()-1; i += 2)
        {
            if(v[i]==1) ma = max(ma,v[i-1]+v[i+1]+1);
        }
        cout<<max(mm+1,ma);

    }
    else if(G==2)
    {
        ll ans=0;
        ll k = 0;
        if (s[0] == 'S')
            k++;
        k++;
        if(v[k]==1)
        {
            ans = v[k-1]+v[k+1];
        }
        else ans = max(v[k-1],v[k+1])+1;
        cout<<ans;
    }
    else if(G==1)
    {
        ll ans=0;
        ll k = 0;
        if (s[0] == 'S')
            k++;
        ans=v[k];
        cout<<ans;
    }
    else cout<<"0";
}