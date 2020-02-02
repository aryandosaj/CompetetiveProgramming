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
    ll t;
    scanf("%lld",&t);
    while (t--)
    {
        ll n;
    scanf("%lld",&n);
         int num=n;
         map<ll,ll> mp;
       while(num%2==0)
       {
           mp[2]++;
        num/=2;
       }
       
       for(int j = 3; j <= sqrt(num); j++)
       {
           while(num%j==0)
           num/=j,mp[j]++;
       }
       if(num>2)
       mp[num]++;
       ll ans=1;
       for(auto i:mp)
       {
           ans*=(2*i.second+1);
       }
       printf("%lld\n",(ans-1)/2);
    }
    return 0;
}