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
        ll n, m,nn=0,mm=0;
        cin >> n >> m;
        ll sum1 = 0, sum2 = 0;
        vector <ll> arr;
        vector <ll> brr;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if(a==0)
            continue;
            arr.push_back(a);
            sum1 += a;
        }

        for (ll j = 0; j < m; j++)
        {
            ll a;
            cin >> a;
            if(a==0)
            continue;
            brr.push_back(a);
            sum2 += a;
        }
        // cout << sum1 << " " << sum2;
        n=arr.size();
        m=brr.size();
        if (sum1 == sum2)
        {
            if (n != m)
                cout << "Alice\n";
            else
            {
                ll flag = 0;
                sort(arr.begin(),arr.end());
                sort(brr.begin(),brr.end());
                for (ll i = 0; i < n; i++)
                {
                    if (arr[i] != brr[i])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag==0)
                cout<<"Bob\n";
                else
                cout<<"Alice\n";
            }
        }
        else
            cout << "Alice\n";
    }
}