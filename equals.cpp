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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll m=MAX;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            m = min(m,arr[i]);
        }
        sort(arr, arr + n);
        map<ll,ll>mp;
        ll c=0;
        ll y;
        ll ans=MAX;

        for(ll i = 0; i < 5; i++)
        {
            y=m-i;
            c=0;
            for(ll j = 0; j < n; j++)
            {
                c+=(arr[j]-y)/5+((arr[j]-y)%5)/2+((arr[j]-y)%5)%2;   
            }
            ans = min(ans,c);
            
        }
        
       
        cout<<ans<<"\n";
    }
}