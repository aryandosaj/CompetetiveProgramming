#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
ll abc[200000][64];
ll power(ll x, ll y, ll p)
{
    ll res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k, x;
    cin >> n >> k >> x;
    ll arr[n];
    // ll m=0;
    // ll m_ind;
    ll bin[64];
    for (ll i = 0; i < 64; i++)
    {
        bin[i] = 0;
    }
    ll m = 0;
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp = arr[i];
        ll j = 0;
        while (temp > 0)
        {
            abc[i][j] = temp % 2;
            bin[j] += temp % 2;
            temp /= 2;
            m = max(m, j);
            j++;
        }
    }
    ll d = pow(2, m);
    ll max_or=0;
    ll best_num=0;
    ll t[64];
    for (ll i = 0; i < n; i++)
    {
        // if (arr[i] / d > 0)
        {
            ll c = 0;
            for (ll j = 0; j < 64; j++)
            {
                t[j] = bin[j] - abc[i][j];
            }
            temp = arr[i]*power(x,k,100000000000000);
            ll k = 0;
            while (temp > 0)
            {
                // abc[i][j] = temp % 2;
                t[k] += temp % 2;
                if(t[k]>0)
                c+=pow(2,k);
                temp /= 2;
                // m = max(m, j);
                k++;
            }
            if(max_or<c)
            {
                max_or=c;
                best_num=arr[i];
                
            }
            c=0;
        }
    }
    cout<<max_or;
}