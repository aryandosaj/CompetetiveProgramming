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
double score(map<ll,bool>mp)
{
    double a=0;
    for(ll i = 1; i <= 9; i++)
    {
        if(mp[i])
        a=a*10+i;

    }
    return a;
}
double calc_max(map<ll,bool> mp)
{
    map<ll,bool> temp;
    double r=0;

    for(ll i = 1; i <= 6; i++)
    {
        
        for(ll j = 1; j <= 6; j++)
        {
            if(mp[i+j])
            {
                temp=mp;
                temp[i+j]=0;
                r+=(1.0/36.0)*(score(temp)+(calc_max(temp)));
            }
            else if(mp[i]&&mp[j])
            {
                temp = mp;
                temp[i]=0,temp[j]=0;
                r+=(1.0/36.0)*(score(temp)+(calc_max(temp)));

            }
            else
            {
                r+=(1.0/36.0)*score(temp);

            }
        }
    }
    return r;
}
double calc_min(map<ll,bool> mp)
{
    map<ll,bool> temp;
    double r=0;

    for(ll i = 1; i <= 6; i++)
    {
        
        for(ll j = 1; j <= 6; j++)
        {
            
            if(mp[i]&&mp[j])
            {
                temp = mp;
                temp[i]=0,temp[j]=0;
                r+=(1.0/36.0)*((calc_min(temp)));

            }
            else if(mp[i+j])
            {
                temp=mp;
                temp[i+j]=0;
                r+=(1.0/36.0)*((calc_min(temp)));

            }
            else
            {
                r+=(1.0/36.0)*score(temp);
            }
        }
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll s;
    cin >> s;
    map<ll, bool> mp_max;
    map<ll, bool> mp_min;
    while (s > 0)
        mp_max[s % 10] = 1, mp_min[s % 10] = 1, s /= 10;
    ll a, b;
    cin >> a >> b;
    ll ans_max, ans_min, ans_max_1, ans_min_1;

    //maximize
    if (mp_max[a + b] == 1)
    {
        ans_max = a + b;
        mp_max[a + b] = 0;
    }
    else if ((mp_max[a] == 1) && (mp_max[b] == 1) && (a != b))
        ans_max = a * 10 + b, mp_max[a] = 0, mp_max[b] = 0;

    else
        ans_max = -1;

    if ((mp_min[a] == 1) && (mp_min[b] == 1) && (a != b))
        ans_min = a * 10 + b, mp_min[a] = 0, mp_min[b] = 0;

    else if (mp_min[a + b] == 1)
    {
        ans_min = a + b;
        mp_min[a + b] = 0;
    }

    else
        ans_min = -1;
    if(ans_min!=-1)
    {
        cout<<ans_min<<" "<<calc_min(mp_min)<<"\n";
    }
    else
    {
        cout<<ans_min<<" "<<score(mp_min)<<"\n";

    }
    if(ans_max!=-1)
    {
        cout<<ans_max<<" "<<calc_max(mp_max)<<"\n";
    }
    else
    {
        cout<<ans_max<<" "<<score(mp_max)<<"\n";

    }
}

