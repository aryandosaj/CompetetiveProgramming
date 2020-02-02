#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll index[1005];
ll ar[1005];
int main()
{
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        index[x] = i + 1;
    }
    for (ll i = 1; i < 1001; i++)
        if (index[i] != 0)
        {
            ll x = index[i];
            ar[x] = i;
        }

    for (int i = 0; i < 1001; i++)
        cout << ar[i] << " ";
}