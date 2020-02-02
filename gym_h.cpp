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
bool isprime(ll n)
{
    ll flag = 0;
    ll root = sqrt(n);
    for (ll i = 2; i <= root; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            return 0;
        }
    }
    return 1;
}
vector <ll> v;
map<ll,ll>mp;
void SieveOfEratosthenes(ll n) 
{ 
   
    bool prime[n+1]; 
    // memset(prime, true, sizeof(prime)); 
    
    for(ll i = 0; i < n+1; i++)
    {
        /* code */
        prime[i]=true;
    }
    
    for (ll p=2; p*p<=n; p++) 
    { 
       
        if (prime[p] == true) 
        { 
           
            for (ll i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          v.push_back(p),mp[p]=1;
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll step=0;
    ll ma=0;
    SieveOfEratosthenes(1e6);
    for(ll i=0;i<v.size();i++)
    {
        
        {
            if(mp[(n-v[i])])
            {
                // ma=max(ma,i);
                n = abs(n-v[i]-v[i]);
                step++;
                // cout<<n<<"\n";
                i=-1;
            }
        }
        if(n<4)
        break;

    }
    cout<<step;
    
}