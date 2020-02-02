#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
ll primeFactors(ll n)
{
    ll sum=0;
    if(n%2==0)
    sum+=2;
    while (n%2 == 0)
    {
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        if(n%i==0)
        sum+=i;
        while (n%i == 0)
        {
            n = n/i;
        }
    }
 
    if (n > 2)
        sum+=n;
        return sum;
}
struct dt
{
    ll n,s;
};
bool comp(dt a,dt b)
{
    return (a.n>b.n);
}


int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       dt arr[n];
       for(ll i = 0; i < n; i++)
       {
           cin>>arr[i].n;
           arr[i].s=primeFactors(arr[i].n);
       }
       sort(arr,arr+n,comp);
        ll ans=0;
        for(ll i = 0; i < n; i++)
        {
            
            for(ll j = i+1; j < n; j++)
            {
                if(((arr[i].n%arr[j].n)==0)&&((arr[i].s%arr[j].s)==0))
                ans++;

            }
            
        }   
        for(ll i = 0; i < n; i++)
        {
            
            for(ll j = i+1; j < n; j++)
            {
                if(((arr[j].n%arr[i].n)==0)&&((arr[j].s%arr[i].s)==0))
                ans++;

            }
            
        } 
        cout<<ans<<"\n";
       
   }
}