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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> v;
    bool prime[1500001]; 
    memset(prime, true, sizeof(prime)); 
    prime[1]=false;

    int c=0;
    int sum=0;
    for (int p=2; p*p<=1500000; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=1500000; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=1500000; p++) 
    { 
        if (prime[p] == true) 
        { 
            c++;
            if(prime[c])
                {
                    sum+=p;
                    v.push_back(sum);
                }
            
        } 
    } 
    // cout<<v.size();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<v[n-1]<<"\n";
    }
    


}