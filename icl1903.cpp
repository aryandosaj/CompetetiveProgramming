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
        ll n, m, k;
        cin >> n >> m >> k;
        if (m > n)
        {
            cout << "-1\n";
            continue;
        }
        ll low=0,high=MAX,mid,ans;
        while(low<high)
        {
            cout<<mid<<"\n";
            mid = (low+high)/2;
            if((n<mid*k)){high = mid-1;continue;}
            if(((n-mid*k)%m==0))
                {
                    ans=mid;
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
                
        }
        cout<<ans<<"\n";
    }
}