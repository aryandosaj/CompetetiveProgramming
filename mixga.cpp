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
        ll arr[n];
        ll e = 0, o = 0,c=0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i])
                if (i % 2 == 0)
                    {
                        if(c>=0)
                        c++;
                        else
                        c--;
                    }
                else
                    {
                        if(c>0)
                        c--;
                        else
                        c++;
                    }
        }
        if(abs(c)>=k)
        {
            cout<<"1\n";
        }
        else
        cout<<"2\n";
    }
}