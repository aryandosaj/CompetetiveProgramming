#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll m=-100000000000;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n,num;
    cin >> n;
    num=n;
    vector <ll> v;
    ll s=0;
    vector <ll> fac;


    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s+=a;
        v.push_back(a);
    }
    if(n%2==0)
    {
        // fac.push_back(2);
        while(n%2==0)
        {
            n=n/2;
        }
    }
    for(int i = 3; i <= n; i+=2)
    {
        if(n%i==0)
        {
            fac.push_back(i);
            while(n%i==0)
            n=n/i;
        }
        if(n<=1)
        break;

    }
    ll sum=0;
    for(int i = 0; i < fac.size(); i++)
    {
        ll f=fac[i];
        ll l=n/f;
        sum=0;
        for(ll j = 0; j < l; j++)
        {
            ll ind=0;
            for(ll k = 0; k < f; k++)
            {
                sum+=v[ind];
                ind+=l;
            }
            m=max(sum,m);
        }
        
    }
    cout<<m;
    
    
    
    cout<<m;
}