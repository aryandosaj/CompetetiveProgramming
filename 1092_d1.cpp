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
    ll n;
    cin >> n;
    ll m = 0;
    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        m = max(m, arr[i]);
    }
    ll flag = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i == (n - 1))
        {
            if ((m - arr[i]) % 2 != 0)
            {
                flag = 1;
                break;
            }
        }
        if ((m - arr[i]) % 2 == 0)
        {
            continue;
        }
        else
        {
            if (abs(arr[i] - arr[i + 1]) % 2 == 0)
            {
                i++;
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1)
    {
        m++;
        for (ll i = 0; i < n; i++)
        {
            if (i == (n - 1))
            {
                if ((m - arr[i]) % 2 != 0)
                {
                    flag = 2;
                    break;
                }
            }
            if ((m - arr[i]) % 2 == 0)
            {
                continue;
            }
            else
            {
                if (abs(arr[i] - arr[i + 1]) % 2 == 0)
                {
                    i++;
                    continue;
                }
                else
                {
                    flag = 2;
                    break;
                }
            }
        }
    }
    if(flag==2)
    cout<<"NO"; else cout<<"YES";
}