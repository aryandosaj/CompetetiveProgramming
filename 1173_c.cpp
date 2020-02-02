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
    ll arr[n], brr[n];
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    for (ll i = 0; i < n; i++)
        cin >> brr[i], mp[brr[i]] = i + 1;
    ll flag = 0, f = 0;
    for (ll i = brr[n - 1], j = n - 1; i >= 1; i--, j--)
    {
        // cout<<brr[j]<<" "<<i<<"\n";
        if (brr[j] != i)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
         
        for (ll i = brr[n - 1] + 1; i <= n; i++)
        {
           

            if (mp[i] == 0)
                continue;
            else
            {
        //    cout<<"Here";
                
                
                if (i - brr[n - 1] > mp[i])
                {
                    continue;
                }
                else
                {
                    f = 1;
                    break;
                }
            }
        }
        if (!f)
        {
        //    cout<<"Here";
            cout << (n - brr[n - 1]);
            return 0;
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans = max(ans, mp[i] + n - i + 1);
    }
    cout << ans;
}