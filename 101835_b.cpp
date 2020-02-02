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
map<ll,vll>mp_male;
map<ll,vll>mp_female;
map<ll,ll> vis;
set<ll>s_p;
void factorise(ll n,ll flag)
{
    ll num = n;
    vll v;
    if(n%2==0)
    {
        v.push_back(2);
        s.insert(2);
        while(n%2==0)
        n/=2;
    }
    for (ll i = 3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        {
            s.insert(i);
            v.push_back(i);
            while(n%i==0)
            n/=i;
        }
    
    }
    if(n>2)
    v.push_back(n);
    if(flag==0)
    {
        for(auto i:v)
        {
            mp_male[i].push_back(num);
        }
    }
    else
    {
        for(auto i:v)
        {
            mp_female[i].push_back(num);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll p[n];
        string s[n];
        vector<ll> male;
        vector<ll> female;
        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
            if (s[i] == "M")
                male.push_back(p[i]);
            else
                female.push_back(p[i]);
        }

        for (auto i:s_p)
        {
            ll temp = min(mp_female[i].size(),mp_male[i].size());
            if(temp==1)
            {
                
            }
        }


    }
}