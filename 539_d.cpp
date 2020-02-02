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
int main()
{
 
    ll n;
    cin>>n;
    ll arr[n];
    ll t = 0;
    map<ll, ll> exist;

    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
        exist[arr[i]]=1;
        if (arr[i] == 1)
            t = 1;
    }
    ll g = 0, flag = 0, l = 0, r = 0, temp = 0;
    ll ans = 0;
    map<ll, ll> mp;
    map<ll, vll> mp2;
    map<ll,ll>e2;
    for (ll i = 0; i < n; i++)
    {
        // cout<<i<<" ";
        if (!flag)
        {
            mp2[0].push_back(i+1);
            ans = max(ans, (ll)0);
            flag = 1;
            l = i;
            mp.clear();
            g = arr[i];
            mp[arr[i]] = 1;
        }
        else
        {
            mp[arr[i]] = 1;
            g = __gcd(g, arr[i]);
            if ((g == 1)||(e2[g]))
            {
                flag = 0, g = 0, i = l;
                continue;
            }
            if (mp[g])
            {
                r = i;
                mp2[r - l].push_back(l+1);
                ans = max(ans, r - l);
            }
            else if(i==n-1)
            {
                e2[g]=1;
                flag = 0, g = 0, i = l;
                continue;
            }
            
            
        }
    }
    if (!t)
    {
       cout<<mp2[ans].size()<<" "<< ans<<"\n";
        for (int i = 0; i < mp2[ans].size(); i++)
        {
            cout<<mp2[ans][i]<<" ";
        }
    }
    else
    {
        cout<<"1 "<<(n-1)<<"\n1";
    }
}