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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll sss = (k) * (k + 1) / 2;
        if (n == sss)
        {
            cout << "0\n";
            continue;
        }
        else if (n < sss)
        {
            cout << "-1\n"; continue;
        }
        sss = (k + 1) * (k + 2) / 2;
        ll arr[k];
        ll jj=2,sum=0;
        for(ll i = 0; i < k; i++)
        {
            arr[i]=jj++;
            sum+=arr[i];
        }
        ll rem = n-sum;
        ll add = rem/k;
        rem = rem%k;
        for(ll i = 0; i < k; i++)
        {
            arr[i]+=add;
        }
        // for(int i = 0; i < k; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        for(ll i = 0; i < rem; i++)
        {
            arr[k-1-i]+=1;
        }
        ll ans=1;
        
        
        for(ll i = 0; i < k; i++)
        {
            ans=(ans*((arr[i]*(arr[i]-1))%MAX))%MAX;
        }
        cout<<ans<<"\n";
    }
}