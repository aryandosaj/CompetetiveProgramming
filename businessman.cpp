#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n;
    cin >> n;
    ll sum = 0;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        ll a, x;
        cin >> a >> x;
        mp[a] = x;
        sum += x;
    }
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll b, x;
        cin >> b >> x;
        if (mp[b] != 0)
        {
            if (x > mp[b])
            {
                sum -= mp[b];
                mp[b] = x;
                sum+=x;
            }
        }
        else
        {
            mp[b] = x;
            sum += x;
        }
    }
    cout << sum;
}